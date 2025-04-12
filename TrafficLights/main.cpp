#include "MainWindow.h"

#include <QApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>
#include <QQuickWidget>
#include "MainWindow.h"
#include "TrafficLightController.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    // Регистрируем класс перед созданием QML-движка
    qmlRegisterType<TrafficLightController>("TrafficLight", 1, 0, "TrafficLightController");

    MainWindow w;

    // Создаем QQuickWidget для отображения QML
    QQuickWidget *qmlWidget = new QQuickWidget();
    qmlWidget->setResizeMode(QQuickWidget::SizeRootObjectToView);
    qmlWidget->setSource(QUrl("qrc:/qml/TrafficLight.qml"));

    // Устанавливаем центральный виджет
    w.setCentralWidget(qmlWidget);
    w.resize(800, 600);
    w.show();

    return a.exec();
}
