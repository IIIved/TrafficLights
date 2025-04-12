#include "TrafficLightController.h"

TrafficLightController::TrafficLightController(QObject *parent)
    : QObject(parent), m_state(Red), m_timer(new QTimer(this))
{
    connect(m_timer, &QTimer::timeout, this, &TrafficLightController::nextState);
    startNormalCycle();
}

int TrafficLightController::currentState() const {
    return m_state;
}

void TrafficLightController::startNormalCycle() {
    m_timer->start(3000);
    m_state = Red;
    emit stateChanged();
}

void TrafficLightController::setBlinkingYellow() {
    m_timer->stop();
    m_state = BlinkingYellow;
    emit stateChanged();
}

void TrafficLightController::turnOff() {
    m_timer->stop();
    m_state = Off;
    emit stateChanged();
}

void TrafficLightController::nextState() {
    switch(m_state) {
    case Red: m_state = RedYellow; break;
    case RedYellow: m_state = Green; break;
    case Green: m_state = Yellow; break;
    case Yellow: m_state = Red; break;
    default: m_state = Red;
    }
    emit stateChanged();
}
