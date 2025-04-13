import QtQuick 2.15
import QtQuick.Controls 2.15
import TrafficLight 1.0

Rectangle {
    id: root
    width: 200
    height: 400
    color: "gray"
    radius: 20
    border.color: "black"
    border.width: 2

    TrafficLightController {
        id: controller
    }

    // Шаблон для ламп
    Component {
        id: lightTemplate
        Rectangle {
            width: 120
            height: 120
            radius: 60
            border.color: "black"
            border.width: 2
        }
    }

    // Красный свет
    Loader {
        id: redLight
        sourceComponent: lightTemplate
        anchors.horizontalCenter: parent.horizontalCenter
        y: 30
        onLoaded: {
            item.color = controller.currentState === TrafficLightController.Red ||
                         controller.currentState === TrafficLightController.RedYellow ?
                         "red" : "#300"
        }
    }

    // Желтый свет
    Loader {
        id: yellowLight
        sourceComponent: lightTemplate
        anchors.horizontalCenter: parent.horizontalCenter
        y: 160
        onLoaded: {
            item.color = (controller.currentState === TrafficLightController.Yellow ||
                         controller.currentState === TrafficLightController.RedYellow ||
                         controller.currentState === TrafficLightController.BlinkingYellow) &&
                         (controller.currentState !== TrafficLightController.BlinkingYellow ||
                         (Math.floor(Date.now() / 500) % 2 === 0)) ?
                         "yellow" : "#330"
        }
    }

    // Зеленый свет
    Loader {
        id: greenLight
        sourceComponent: lightTemplate
        anchors.horizontalCenter: parent.horizontalCenter
        y: 290
        onLoaded: {
            item.color = controller.currentState === TrafficLightController.Green ?
                         "green" : "#030"
        }
    }

    // Кнопки управления
    Column {
        anchors.top: parent.bottom
        anchors.topMargin: 20
        spacing: 10

        Button {
            text: "Нормальный режим"
            onClicked: controller.startNormalCycle()
        }

        Button {
            text: "Мигающий желтый"
            onClicked: controller.setBlinkingYellow()
        }

        Button {
            text: "Выключить"
            onClicked: controller.turnOff()
        }

        Button {
            text: "Сменить стиль"
            onClicked: root.style = root.style === "default" ? "modern" : "default"
        }
    }

    // Обновление цветов при изменении состояния
    function getRedColor(state) {
        return (state === TrafficLightController.Red ||
               state === TrafficLightController.RedYellow) ? "red" : "#300";
    }

    function getYellowColor(state) {
        if (state === TrafficLightController.BlinkingYellow) {
            return (Math.floor(Date.now() / 500) % 2 === 0) ? "yellow" : "#330";
        }
        return (state === TrafficLightController.Yellow ||
               state === TrafficLightController.RedYellow) ? "yellow" : "#330";
    }

    function getGreenColor(state) {
        return (state === TrafficLightController.Green) ? "green" : "#030";
    }

    Connections {
        target: controller
        function onStateChanged() {
            var state = controller.currentState;
            redLight.item.color = getRedColor(state);
            yellowLight.item.color = getYellowColor(state);
            greenLight.item.color = getGreenColor(state);

            if (state === TrafficLightController.Off) {
                redLight.item.color = "#300";
                yellowLight.item.color = "#330";
                greenLight.item.color = "#030";
            }
        }
    }
}
