#include "i_diagnose.h"

void Diagnose::runDiagnostics(std::string textstatus, bool door_is_open){
    report = Report {textstatus, door_is_open};
}

Report Diagnose::getReport(){
    return report;
}
