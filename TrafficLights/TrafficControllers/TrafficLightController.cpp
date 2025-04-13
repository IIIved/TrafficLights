#include "TrafficLightController.h"
#include "TrafficState/RedState.h"

TrafficLightController::TrafficLightController(QObject *parent)
    : QObject(parent), _currentState(std::make_unique<RedState>())
{
    connect(&_timer, &QTimer::timeout, this, &TrafficLightController::handleTimeout);
    _currentState->enter(this);
    startNormalCycle();
    emit stateChanged();
}

TrafficLightController::~TrafficLightController() {
}

int TrafficLightController::currentState() const {
    return _currentState ? _currentState->stateId() : -1;
}

QString TrafficLightController::stateName() const {
    return _currentState ? _currentState->stateName() : "Invalid";
}

void TrafficLightController::setTimerInterval(int ms) {
    _timer.start(ms);
}

void TrafficLightController::setState(std::unique_ptr<ITrafficLightState> newState) {
    if (newState) {
        _currentState = std::move(newState);
        _currentState->enter(this);
        emit stateChanged();
    }
}

void TrafficLightController::handleTimeout()
{
    if (_currentState) {
        auto* next = _currentState->nextState();
        if (next) {
            _currentState.reset(next);
            _currentState->enter(this);
            emit stateChanged();
        }
    }
}

void TrafficLightController::startNormalCycle()
{
    setState(std::make_unique<RedState>());
    _timer.start(3000);
    emit stateChanged();
}

void TrafficLightController::setBlinkingYellow()
{
    _timer.stop();
    emit stateChanged();
}

void TrafficLightController::turnOff()
{
    _timer.stop();
    emit stateChanged();
}
