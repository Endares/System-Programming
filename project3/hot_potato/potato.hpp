#ifndef POTATO_H
#define POTATO_H

#include <cstring>
#include <iostream>
using namespace std;


#define MAX_HOPS 512
#define MAX_TRACE_LEN (MAX_HOPS + 1)

class Potato
{
public:
  int remainHops; // number of remaining hops
  int countHops; // current counts of hops
  int path[MAX_TRACE_LEN];
public:
  Potato() : remainHops(0), countHops(0) {
    memset(path, 0, sizeof(path)); // set path[] to all 0
  }
  Potato(int remainHops) : remainHops(remainHops), countHops(0) {
    memset(path, 0, sizeof(path)); // set path[] to all 0
  }
  void printPath() {
    //cout << "countHop = " << countHops << endl;
    cout << "Trace of potato:" << endl;
    string split = ",";
    for (int i = 0; i < countHops; ++i) {
      cout << path[i] << split;
    }
    cout << endl;
  }

  void addToPath(int player_id) {
    if (countHops < MAX_TRACE_LEN) {
        path[countHops] = player_id;
        ++countHops;
    } else {
        // We are out of space -- handle error or ignore
        std::cerr << "Error: path array is full! Cannot add more players.\n";
    }
  }
};


#endif
