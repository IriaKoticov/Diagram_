#include "i_status_display_controller.h"
#include <string>

StateController::StateController() {};

void StateController::updateDisplay(std::string text) {
    statusText = text;
}

std::string StateController::getStatus() {
    return statusText;
}
