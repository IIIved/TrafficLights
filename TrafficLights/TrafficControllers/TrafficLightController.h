#pragma once

#include <QObject>
#include <QTimer>
#include <memory>

#include "TrafficState/ITrafficLightState.h"

class TrafficLightController : public QObject {
    Q_OBJECT
    Q_PROPERTY(int currentState READ currentState NOTIFY stateChanged)
    Q_PROPERTY(QString stateName READ stateName NOTIFY stateChanged)

    Q_ENUMS(TrafficLightStateEnum)

public:

    enum TrafficLightStateEnum {
        Off = 0,
        BlinkingYellow,
        Red,
        RedYellow,
        Yellow,
        Green
    };

    explicit TrafficLightController(QObject *parent = nullptr);
    ~TrafficLightController();

    int currentState() const;
    QString stateName() const;

    Q_INVOKABLE void startNormalCycle();
    Q_INVOKABLE void setBlinkingYellow();
    Q_INVOKABLE void turnOff();

    void setTimerInterval(int ms);
    void setState(std::unique_ptr<ITrafficLightState> newState);

signals:
    void stateChanged();

private slots:
    void handleTimeout();

private:
    std::unique_ptr<ITrafficLightState> _currentState;
    QTimer _timer;
};
