QT += core gui qml quick quickwidgets

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

SOURCES += \
    TrafficState/GreenState.cpp \
    TrafficState/RedState.cpp \
    TrafficState/YellowState.cpp \
    TrafficState/RedYellowState.cpp \
    TrafficControllers/TrafficLightController.cpp \
    main.cpp \
    MainWindow.cpp

HEADERS += \
    TrafficState/GreenState.h \
    TrafficState/RedState.h \
    TrafficState/YellowState.h \
    TrafficState/RedYellowState.h \
    TrafficState/ITrafficLightState.h \
    TrafficControllers/TrafficLightController.h \
    MainWindow.h

FORMS += \
    MainWindow.ui

RESOURCES += qml.qrc

