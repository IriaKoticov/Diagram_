#include "optimize.h"
#include "requests.h"

std::optional<int> Optimizer::nextTarget(
    const ElevatorState& state,
    const Requests& requests
) {
    int current = state.currentFloor;

    if (state.direction == Direction::Up || state.direction == Direction::Idle) {
        auto it = requests.up.lower_bound(current);
        if (it != requests.up.end())
            return *it;

        if (!requests.down.empty())
            return *requests.down.rbegin();
    }

    if (state.direction == Direction::Down) {
        auto it = requests.down.lower_bound(current);
        if (it != requests.down.begin()) {
            --it;
            return *it;
        }

        if (!requests.up.empty())
            return *requests.up.begin();
    }

    return std::nullopt;
}
