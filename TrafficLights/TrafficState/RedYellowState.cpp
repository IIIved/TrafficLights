#include "RedYellowState.h"
#include "GreenState.h"
#include "TrafficControllers/TrafficLightController.h"

void RedYellowState::enter(TrafficLightController* controller) {
    controller->setTimerInterval(1000);
}

ITrafficLightState* RedYellowState::nextState() {
    return new GreenState();
}

int RedYellowState::stateId() const { return TrafficLightController::RedYellow; }

QString RedYellowState::stateName() const { return "Red"; }
