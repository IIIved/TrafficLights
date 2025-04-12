#include "TrafficLightController.h"

TrafficLightController::TrafficLightController(QObject *parent)
    : QObject(parent), _state(Red), _timer(new QTimer(this))
{
    connect(_timer, &QTimer::timeout, this, &TrafficLightController::nextState);
    startNormalCycle();
}

int TrafficLightController::currentState() const {
    return _state;
}

void TrafficLightController::startNormalCycle() {
    _timer->start(3000);
    _state = Red;
    emit stateChanged();
}

void TrafficLightController::setBlinkingYellow() {
    _timer->stop();
    _state = BlinkingYellow;
    emit stateChanged();
}

void TrafficLightController::turnOff() {
    _timer->stop();
    _state = Off;
    emit stateChanged();
}

void TrafficLightController::nextState() {
    switch(_state) {
    case Red: _state = RedYellow; break;
    case RedYellow: _state = Green; break;
    case Green: _state = Yellow; break;
    case Yellow: _state = Red; break;
    default: _state = Red;
    }
    emit stateChanged();
}
