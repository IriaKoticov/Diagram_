#ifndef STATECONTROLLER
#define STATECONTROLLER

#include <iostream>
#include <string>

class StateController{
    std::string statusText;
    public:
    StateController();
    void updateDisplay(std::string text);
    std::string getStatus();
};

#endif
