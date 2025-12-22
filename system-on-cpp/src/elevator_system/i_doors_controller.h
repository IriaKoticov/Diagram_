#ifndef DOORCONTROLLER
#define DOORCONTROLLER

class DoorsController {
    bool isOpen = false;
    public:
    void open();
    void close();
    bool get_door_state();
};

#endif
