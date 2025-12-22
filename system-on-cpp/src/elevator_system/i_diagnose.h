#ifndef DIAGNOSE
#define DIAGNOSE

#include <iostream>

struct Report {

    std::string text_on_display;
    bool status_Door;

};


class Diagnose {
    Report report;
    public:
    void runDiagnostics(std::string textstatus, bool door_is_open);
    Report getReport();
};

#endif
