#include "MainWindow.h"

#include <QApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>
#include <QQuickWidget>
#include "MainWindow.h"
#include "TrafficLightController.h"

Q_DECLARE_METATYPE(TrafficLightController::State)

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    // Регистрируем тип для QML
    qmlRegisterType<TrafficLightController>("TrafficLight", 1, 0, "TrafficLightController");

    MainWindow w;
    w.show();

    return a.exec();
}
