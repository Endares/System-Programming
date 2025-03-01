#ifndef NETWORK_H
#define NETWORK_H

#include <cstring>
#include <iostream>
#include <netdb.h>
#include <arpa/inet.h>
using namespace std;


/**
 * Get client's port number
 */
int get_port(int fd) {
    struct sockaddr_in addr;
    socklen_t addr_len = sizeof(addr);
    if (getsockname(fd, (struct sockaddr *)&addr, &addr_len) == -1) {
        perror("getsockname");
        // handle error
    }
    int local_port = ntohs(addr.sin_port);
    return local_port;  
}

/**
 * Listening for a client's connection request from server_fd. 
 * Server accepts connection and returns client_fd. TCP connection is build since.
 * accept() prototype: int accept(int s, struct sockaddr *addr, socklen_t *addrlen);
 * accept() returns a new socket descriptor for requests coming from listening socket
 */
int accept_connection(int server_fd, string &client_ip) {
    struct sockaddr_storage client_addr;
    socklen_t addr_size = sizeof(client_addr);
    int client_fd = accept(server_fd, (struct sockaddr*)&client_addr, &addr_size);
    if (client_fd == -1) {
        perror("accept");
        exit(EXIT_FAILURE);
    }

    // TODO
    // client_ip = "client_ip_placeholder";
    struct sockaddr_in *temp = (struct sockaddr_in *)&client_addr;
    client_ip = inet_ntoa(temp->sin_addr);
    return client_fd;
}

/**
 * create a listening socket, accept message from any other ports
 */
int init_server(const char *port_name) {
    // hints: tell getaddrinfo() what kind of info we want
    struct addrinfo hints, *res;
    int listen_fd;

    // 1. get address info by calling getaddrinfo()
    memset(&hints, 0, sizeof hints);
    hints.ai_family = AF_UNSPEC;       // IPv4 or IPv6
    hints.ai_socktype = SOCK_STREAM;   // TCP, reliable (UDP: SOCK_DGRAM)
    hints.ai_flags = AI_PASSIVE;       // fill in automatically with the IP addr of my computer
    if (getaddrinfo(NULL, port_name, &hints, &res) != 0) {
        cerr << "getaddrinfo error." << endl;
        exit(EXIT_FAILURE);
    }

    // 2. get a new socket fd for listening socket by calling socket()
    listen_fd = socket(res->ai_family, res->ai_socktype, res->ai_protocol);
    if (listen_fd == -1) {
        perror("socket");
        exit(EXIT_FAILURE);
    }

    // 3. socket settings
    int optval = 1; // socket setting: SO_REUSEADDR(1) is true
    if (setsockopt(listen_fd, SOL_SOCKET, SO_REUSEADDR, &optval, sizeof optval)) {
        perror("setsockopt");
        exit(EXIT_FAILURE);
    }

    // 4. bind a socket to a specifc port# on a specific machine (IP addr.)
    // int bind(int sockfd, struct sockaddr *my_addr, socklen_t addrlen);
    if (bind(listen_fd, res->ai_addr, res->ai_addrlen) == -1) {
        perror("bind");
        exit(EXIT_FAILURE);
    }

    // 5. release res memory
    freeaddrinfo(res);    

    // 6. listen for requests from any other hosts
    if (listen(listen_fd, 100) == -1) { // backlog = 100
        cerr << "Error: cannot listen on socket" << endl; 
        // cerr << "  (" << hostname << "," << port << ")" << endl;
        return -1;
    } 

    return listen_fd;
}



/**
 * Establish TCP connection with "server" by connect() to it, return client_fd
 */
int init_client(const char* hostname, const char* port_name) {
    struct addrinfo hints, *res;
    memset(&hints, 0, sizeof(hints));
    hints.ai_family = AF_UNSPEC;       // Support both IPv4 and IPv6
    hints.ai_socktype = SOCK_STREAM;   // TCP

    // get master's ip addr.etc so as to connect to it
    if (getaddrinfo(hostname, port_name, &hints, &res) != 0) {
        cerr << "getaddrinfo error." << endl;
        exit(EXIT_FAILURE);
    }
    
    int socket_fd = socket(res->ai_family, res->ai_socktype, res->ai_protocol);
    if (socket_fd == -1) {
        perror("socket");
        exit(EXIT_FAILURE);
    }

    // connect to server
    if (connect(socket_fd, res->ai_addr, res->ai_addrlen) == -1) {
        perror("Failed to connect to server");
        exit(EXIT_FAILURE);
    }

    freeaddrinfo(res);
    return socket_fd;
}

#endif