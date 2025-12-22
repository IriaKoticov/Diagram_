#ifndef OPTIMIZE
#define OPTIMIZE
#include <optional>
#include "requests.h"

enum class Direction {
    Up,
    Down,
    Idle
};

struct ElevatorState {
    int currentFloor;
    Direction direction;
};

class Optimizer {
public:
    std::optional<int> nextTarget(
        const ElevatorState& state,
        const Requests& requests
    );
};


#endif
