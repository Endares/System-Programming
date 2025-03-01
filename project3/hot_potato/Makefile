CXX = g++
CXXFLAGS = -std=c++11 -Wall

TARGETS = ringmaster player

HEADERS = potato.hpp player.hpp network.hpp

all: $(TARGETS)

ringmaster: ringmaster.cpp $(HEADERS)
	$(CXX) $(CXXFLAGS) ringmaster.cpp -o ringmaster

player: player.cpp $(HEADERS)
	$(CXX) $(CXXFLAGS) player.cpp -o player

clean:
	rm -f $(TARGETS)
