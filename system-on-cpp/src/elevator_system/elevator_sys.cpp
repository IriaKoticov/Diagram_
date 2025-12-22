#include "elevator_sys.h"
#include <cstddef>
#include <iostream>

ElevatorSystem::ElevatorSystem(std::size_t max_floor_) : currentfloor(0),
      direction(Direction::Idle),
      max_floor( max_floor_),
     is_emergency(false) {}

void ElevatorSystem::step() {
         ElevatorState state{currentfloor, direction};

         auto target = optimize.nextTarget(state, requests);

         if (!target) {
             direction = Direction::Idle;
             std::cout << "Idle at floor " << currentfloor << "\n";
             updateStatus();
             return;
         }

         if (*target == currentfloor) {
             openDoors();
             requests.remove(currentfloor);
             std::cout << "Open a Door at " << currentfloor << "\n";
             updateStatus();
             return;
         }

         moveOneFloorToward(*target);
     }//Функция для loop

void ElevatorSystem::moveOneFloorToward(int target) {
         if (target > currentfloor) {
             direction = Direction::Up;
             ++currentfloor;
         } else {
             direction = Direction::Down;
             --currentfloor;
         }

         std::cout << "Moving to floor " << currentfloor << "\n";
     }//Cимуляция движения

void ElevatorSystem::callElevator(int floor) {
    if (floor < max_floor-1) requests.addRequest(floor, currentfloor);
    return;
}//Реализовать сначала Req

void ElevatorSystem::selectFloor(int floor){
    if (floor < max_floor-1) requests.addRequest(floor, currentfloor);
    return;
}//Реализовать сначала Req

void ElevatorSystem::openDoors(){
    if (is_emergency){
        return;
    }
    doors_Controller.open();
}//Реализовать контроллер двери

void ElevatorSystem::closeOpens(){
    doors_Controller.close();
    updateStatus();

}//Реализовать контроллер двери

void ElevatorSystem::updateStatus(){
    std::string direct_text;
    switch (direction) {
        case Direction::Up: {
            direct_text = "up";
            break;
        }
        case Direction::Down:{
            direct_text = "down";
            break;
        }
        case Direction::Idle:{
            direct_text = "stand";
            break;
        }
    }

    std::stringstream ss;
    ss << direct_text << " " << currentfloor << " ";
    std::string text = ss.str();
    state_Controller.updateDisplay(text);
}//Реализовать контроллер Статус меню

bool ElevatorSystem::emergencyStop(){
    if (is_emergency == false) {
        return true;
    } else {
        openDoors();
        return false;
    }
}//поменять флаг и отправить сигнал

Report ElevatorSystem::performDiagnostics(){
    diagnose.runDiagnostics(state_Controller.getStatus(), doors_Controller.get_door_state());
    return diagnose.getReport();
}//контроллер диагностики
