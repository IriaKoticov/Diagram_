#ifndef ELEVATOR_SYSTEM
#define ELEVATOR_SYSTEM

#include <iostream>
#include <sstream>
#include <cstddef>
#include "i_diagnose.h"
#include "i_doors_controller.h"
#include "i_status_display_controller.h"
#include "../requests/requests.h"
#include "../requests/optimize.h"
#include <format>


class ElevatorSystem {
    private:

    int max_floor;
    DoorsController doors_Controller;
    StateController state_Controller;
    Diagnose diagnose;
    Requests requests;
    Optimizer optimize;

    int currentfloor;
    Direction direction;
    bool is_emergency;

    void moveOneFloorToward(int target);
    void openDoors();
    void closeOpens();

    public:
    ElevatorSystem(std::size_t max_floor_);
    ~ElevatorSystem() = default;
    void callElevator(int floor);
    void selectFloor(int floor);
    void step();
    void updateStatus();
    bool emergencyStop();
    Report performDiagnostics();
};

#endif
