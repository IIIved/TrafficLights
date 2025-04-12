#pragma once

#include <QObject>
#include <QTimer>

class TrafficLightController : public QObject
{
    Q_OBJECT
    Q_PROPERTY(int currentState READ currentState NOTIFY stateChanged)

public:
    enum State {
        Red,
        RedYellow,
        Green,
        Yellow,
        Off,
        BlinkingYellow
    };
    Q_ENUM(State)

    explicit TrafficLightController(QObject *parent = nullptr);

    int currentState() const;

    Q_INVOKABLE void startNormalCycle();

    Q_INVOKABLE void setBlinkingYellow();

    Q_INVOKABLE void turnOff();

signals:
    void stateChanged();

private slots:
    void nextState();

private:
    State m_state;
    QTimer *m_timer;
};
