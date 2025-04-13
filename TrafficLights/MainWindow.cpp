#include "MainWindow.h"

#include "ui_MainWindow.h"

#include <QQmlError>
#include <QVBoxLayout>
#include <QDebug>
#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    _qmlWidget = new QQuickWidget(this);
    _qmlWidget->setResizeMode(QQuickWidget::SizeRootObjectToView);

    connect(_qmlWidget, &QQuickWidget::statusChanged, [this](QQuickWidget::Status status) {
        if (status == QQuickWidget::Error) {
            QStringList errors;
            for (const QQmlError &error : _qmlWidget->errors()) {
                errors.append(error.toString());
            }
            qDebug() << "QML Errors:" << errors.join("\n");
            QMessageBox::critical(this, "QML Error", errors.join("\n"));
        }
        else if (status == QQuickWidget::Ready) {
            qDebug() << "QML loaded successfully";
        }
    });

    _qmlWidget->setSource(QUrl("qrc:/qml/TrafficLights.qml"));

    QVBoxLayout *layout = new QVBoxLayout(ui->trafficLightWidget);
    layout->addWidget(_qmlWidget);
    layout->setContentsMargins(0, 0, 0, 0);
    ui->trafficLightWidget->setLayout(layout);

    resize(250, 500);
}

MainWindow::~MainWindow()
{
    delete ui;
}
