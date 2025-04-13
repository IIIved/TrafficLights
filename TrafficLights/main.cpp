#include "MainWindow.h"
#include "MainWindow.h"
#include "TrafficControllers/TrafficLightController.h"

#include <QApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>
#include <QQuickWidget>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    qmlRegisterType<TrafficLightController>("TrafficLight", 1, 0, "TrafficLightController");

    MainWindow w;
    w.show();

    return a.exec();
}
