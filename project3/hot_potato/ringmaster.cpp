#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <netdb.h>
#include <vector>
#include <sys/types.h>
#include <sys/select.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include "potato.hpp"
#include "player.hpp"
#include "network.hpp"
#include <time.h>
#include <sys/select.h>
#include <cassert>

void report_error(string msg) {
    cerr<< "Error: " << msg << endl;
}


/**
 * Set up for all players and fill in the vector<Player> and conncet to server with player_port
 * send() prototype: ssize_t send(int socket_fd, const void *buf, size_t len, int flags);
 */
void set_players(int server_fd, int num_players, vector<Player>& player_list) {
    for (int i = 0 ; i < num_players; ++i) {
        int player_port; // player to server connection
        string player_ip;
        int p_fd, p_port;
        string p_ip;
        p_fd = accept_connection(server_fd, player_ip);
        p_ip = player_ip;
        // server send player's index(id) to player's socket
        send(p_fd, &i, sizeof(i), 0); // 0 - normal message
        // server send players' number to player's socket
        send(p_fd, &num_players, sizeof(num_players), 0);
        // receive the port_num for current player to listen to its neighbor
        // TODO : 0 ? WAITALL?
        recv(p_fd, &player_port, sizeof(player_port), MSG_WAITALL);
        p_port = player_port;
        Player p(p_fd, p_port, p_ip);
        player_list.push_back(p);
        //print message
        cout << "Player " << i << " is ready to play" << endl;
        //cout << "Info of Player " << i << ": ip:" << p_ip << "  fd: " << p_fd << "  port: " << p_port << endl;
    }
}

void print_player_list(vector<Player>& player_list) {
    cout << "Player list: " << endl;
    int n = player_list.size();
    for (int i = 0; i < n; ++i) {
        cout << "Player " << i << "  port: " << player_list[i].port <<
        "   fd: " << player_list[i].fd << "   ip: " << player_list[i].ip << endl;
    }
}

/**
 * Form the ring among players: 
 * Ringmaster send each player their right neighbor's info
 * While: (int player.cpp) each player listen to its right neighbor 
 * on its player_listen_fd, then set up their TCP connection
 */
void send_neighbor_info(vector<Player>& player_list) {
    int n = player_list.size();
    for (int i = 0; i < n; ++i) {
        int next_id = (i + 1) % n;
        MetaInfo meta_info;
        meta_info.port = player_list[next_id].port;
        strcpy(meta_info.ip, (player_list[next_id].ip).c_str());
        send(player_list[i].fd, &meta_info, sizeof(meta_info), 0);
    }
}

/**
 * TCP connection setup:
 * 1. client request a connection to server by connect()
 * 2. server accepts a connection from client by accept()
 * TCP connection close:
 * 1. BOTH sides should eventually close their own socket file 
 *    descriptors when they no longer need the connection.
 */

/**
 * Toss the potato to a random player in the beginning
 */
void assign_potato(Potato& potato, vector<Player>& player_list) {
    int n = player_list.size();
    // get a random seed at the beginning of the program to make 
    // sure everytime we have different random sequence
    srand((unsigned int)time(NULL)); 
    int rand_index = rand() % n; // [0, n)
    cout << "Ready to start the game, sending potato to player " << rand_index << endl;
    // return value of send() is the number of bytes it sends. -1: error; < len: broken
    if (send(player_list[rand_index].fd, &potato, sizeof(potato), 0) != sizeof(potato)) {
        cout << "The potato is broken!" << endl;
    }
}

/**
 * Announce the end of the game to all players by sending them ending message msg
 */
void annouce_end(vector<Player>& player_list, Potato& p) {
    for (int i = 0; i < player_list.size(); ++i) {
        send(player_list[i].fd, &p, sizeof(p), 0);
    }
}


/**
 * select() prototype: 
 * int select(int n, fd_set *readfds, fd_set *writefds, fd_set *exceptfds, struct timeval *timeout);
 * n is the max socket_fd + 1
 * return value: 1.success: |fd_set|; 2. timeout: 0; 3. error: -1
 */
void wait_end(vector<Player>& player_list, Potato& potato) {
    fd_set readfds;
    FD_ZERO(&readfds);
    int max_fd = -1;
    for (size_t i = 0; i < player_list.size(); i++) {
        FD_SET(player_list[i].fd, &readfds);
        if (player_list[i].fd > max_fd) {
            max_fd = player_list[i].fd;
        }
    }
    int status = select(max_fd + 1, &readfds, NULL, NULL, NULL);
    if (status < 0) {
        perror("select");
        exit(EXIT_FAILURE);
    }

    // traverse all players, find the one ends the game
    for (size_t i = 0; i < player_list.size(); i++) {
        if (FD_ISSET(player_list[i].fd, &readfds)) {
            int n = recv(player_list[i].fd, &potato, sizeof(potato), MSG_WAITALL);
            if (n != sizeof(potato)) {
                perror("recv");
                exit(EXIT_FAILURE);
            }
            break;
        }
    }
}

/**
 * Close all TCP connection by close() sockets
 * close() prototype: int close(int s);
 */
void close_all(int server_fd, vector<Player>& player_list) {
    for (int i = 0; i < player_list.size(); ++i) {
        close(player_list[i].fd);
    }
    close(server_fd);
}


/**
 * 1.Establish N network socket connections with N number of players and provide relevant 
 * information to each player (see Communication Machanism section below for details) 
 * 2. Create a "potato" object as described above 
 * 3. Randomly select a player and send the "potato" to the selected player 
 * 4. At the end of the game (when the ringmaster receive the potato from the player who 
 * is "it"), print a trace of the potato to the screen.
 * 5. Shut the game down by sending a message to each player
 */
int main(int argc, char *argv[]) {
    if (argc != 4) {
        fprintf(stderr, "Usage: %s <port_num> <num_players> <num_hops>\n", argv[0]);
        exit(1);
    }
    
    const char *port_name = argv[1];
    int num_players = atoi(argv[2]);
    int num_hops = atoi(argv[3]);

    if (num_players <= 1 || num_hops < 0 || num_hops > 512) {
        fprintf(stderr, "Invalid arguments.\n");
        exit(1);
    }

    cout << "Potato Ringmaster" << endl;
    cout << "Players = " << num_players << endl;
    cout << "Hops = " << num_hops << endl;
    // TODO: check validity

    /* 1. Establish network with players and set them up */
    // create a server socket to listen to requests from any port
    int server_fd = init_server(port_name);
    // build TCP connection with players and set up all players
    vector<Player> player_list;
    set_players(server_fd, num_players, player_list);
    // print_player_list(player_list);
    // players build TCP connection with its left and right neighbors
    send_neighbor_info(player_list);

    /* 2. Create a "potato" object */
    Potato potato(num_hops);
    if (num_hops <= 0) {
        cout << "Game exits because of <= 0 nums of hops!" << endl;
        return EXIT_SUCCESS;
    }
    // cout << "Potato created successfully with hop number of " << potato.remainHops << endl;

    /* 3. send the potato to a random player */
    assign_potato(potato, player_list);

    // TODO: wait for mesg from player
    wait_end(player_list, potato);
    /* 5. annouce end of the game to all players */
    assert(potato.remainHops == 0);
    annouce_end(player_list, potato);
    potato.printPath();
    close_all(server_fd, player_list);

    return EXIT_SUCCESS;
}
