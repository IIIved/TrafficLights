#include "GreenState.h"
#include "TrafficControllers/TrafficLightController.h"
#include "YellowState.h"

void GreenState::enter(TrafficLightController* controller) {
    controller->setTimerInterval(4000);
}

ITrafficLightState* GreenState::nextState() {
    return new YellowState();
}

int GreenState::stateId() const { return TrafficLightController::Green; }

QString GreenState::stateName() const { return "Red"; }
