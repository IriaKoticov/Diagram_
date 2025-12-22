#include "i_doors_controller.h"


void DoorsController::open(){
    if (isOpen == true) {
        return;
    } else {
        isOpen = true;
        return;
    }
}

void DoorsController::close(){
    if (isOpen == true) {
        isOpen = false;
        return;
    } else {
        return;
    }
}

bool DoorsController::get_door_state(){
    return isOpen;
}
