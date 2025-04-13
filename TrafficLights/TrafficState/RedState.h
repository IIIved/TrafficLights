#pragma once

#include "ITrafficLightState.h"

class RedState : public ITrafficLightState
{
public:
    //!
    void enter(TrafficLightController* controller) override;

    //!
    ITrafficLightState* nextState() override;

    //!
    int stateId() const override;

    //!
    QString stateName() const override;
};
