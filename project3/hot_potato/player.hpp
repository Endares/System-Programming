#ifndef PLAYER_H
#define PLAYER_H

#include <string>
#include <string.h>
using namespace std;
class Player {
public:
    int fd;     // fd to master
    int port;   // listen port
    string ip;
public:
    Player() : fd(0), port(0), ip("") {}
    Player(int fd, int port, string ip) : fd(fd), port(port), ip(ip) {}
};

class MetaInfo {
public:
  char ip[100];
  int port;
  MetaInfo() : port(-1) {
    memset(ip, 0, sizeof(ip));
  }
};

#endif