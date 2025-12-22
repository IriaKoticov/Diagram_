#include "requests.h"

void Requests::addRequest(int floor, int currentFloor) {
    if (floor > currentFloor)
        up.insert(floor);
    else if (floor < currentFloor)
        down.insert(floor);
}

void Requests::remove(int floor) {
    up.erase(floor);
    down.erase(floor);
}

bool Requests::empty() const {
    return up.empty() && down.empty();
}
