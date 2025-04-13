#include "YellowState.h"
#include "RedState.h"
#include "TrafficControllers/TrafficLightController.h"


void YellowState::enter(TrafficLightController* controller) {
    controller->setTimerInterval(2000);
}

ITrafficLightState* YellowState::nextState() {
    return new RedState();
}

int YellowState::stateId() const { return TrafficLightController::Yellow; }

QString YellowState::stateName() const { return "Red"; }
