#include "elevator_system/elevator_sys.h"

int main() {
    ElevatorSystem elevator(10);

        for (int tick = 0; tick < 30; ++tick) {
            std::cout << "\nTICK\t" << tick << " \n";

            switch (tick) {
                case 1:
                    std::cout << "Call elevator at floor 3\n";
                    elevator.callElevator(3);
                    break;

                case 3:
                    std::cout << "Call elevator at floor 7\n";
                    elevator.callElevator(7);
                    break;

                case 6:
                    std::cout << "Passenger selects floor 9\n";
                    elevator.selectFloor(9);
                    break;

                case 10:
                    std::cout << "Passenger selects floor 2\n";
                    elevator.selectFloor(2);
                    break;

                case 15:
                    std::cout << "Call elevator at floor 5\n";
                    elevator.callElevator(5);
                    break;

                default:
                    break;
            }

            elevator.step();
        }

        return 0;
}
