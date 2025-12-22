#ifndef REQUESTS
#define REQUESTS

#include <set>

class Requests {
public:
    std::set<int> up;
    std::set<int> down;

    void addRequest(int floor, int currentFloor);
    void remove(int floor);
    bool empty() const;
};

#endif
