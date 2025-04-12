QT += core gui qml quick quickwidgets

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

SOURCES += \
    TrafficLightController.cpp \
    main.cpp \
    MainWindow.cpp

HEADERS += \
    MainWindow.h \
    TrafficLightController.h

FORMS += \
    MainWindow.ui

RESOURCES += qml.qrc

