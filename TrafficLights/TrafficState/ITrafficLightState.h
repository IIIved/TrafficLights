#pragma once

#include <QObject>

class TrafficLightController;

class ITrafficLightState : public QObject
{
    Q_OBJECT
public:
    virtual ~ITrafficLightState() = default;

    //!
    virtual void enter(TrafficLightController* controller) = 0;

    //!
    virtual ITrafficLightState* nextState() = 0;

    //!
    virtual int stateId() const = 0;

    //!
    virtual QString stateName() const = 0;
};
