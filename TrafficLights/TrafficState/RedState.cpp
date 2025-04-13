#include "RedState.h"
#include "RedYellowState.h"
#include "TrafficControllers/TrafficLightController.h"

void RedState::enter(TrafficLightController* controller)
{
    controller->setTimerInterval(3000);
}

ITrafficLightState* RedState::nextState()
{
    return new RedYellowState();
}

int RedState::stateId() const { return TrafficLightController::Red; }

QString RedState::stateName() const { return "Red"; }

