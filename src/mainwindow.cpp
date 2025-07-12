#include "mainwindow.h"

#include <QComboBox>
#include <QFile>
#include <QJsonArray>
#include <QJsonDocument>
#include <QJsonObject>
#include <QLabel>
#include <QMainWindow>
#include <QVBoxLayout>
#include <QDebug>

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent){
    createWindow();
}

void MainWindow::createWindow() {
    this->setFixedSize(400, 600);
    this->setWindowTitle("BUBLYAASH VPN");
    this->setStyleSheet("background-image: url(':/media/background.png');"
                        "background-repeat: no-repeat;"
                        "background-position: center;");
    QWidget *widget = new QWidget(this);
    this->setCentralWidget(widget);

    QVBoxLayout *layout = new QVBoxLayout(widget);
    layout->setAlignment(Qt::AlignCenter);

    QLabel *label = new QLabel("BUBLYAASH");
    label->setStyleSheet("font-size: 24px; color: white;");
    label->setAlignment(Qt::AlignTop);

    QComboBox *serversList = new QComboBox(this);
    serversList->setStyleSheet("background: transparent; border: none; color: white;");
    serversList->setFixedSize(200, 50);

    QFile file(":/servers.json");
    if (!file.open(QIODevice::ReadOnly)) {
        qDebug() << "File open error";
        return;
    }

    QByteArray data = file.readAll();
    file.close();

    QJsonDocument doc = QJsonDocument::fromJson(data);
    if (!doc.isArray()) {
        qDebug() << "JSON is not an array";
        return;
    }

    QJsonArray serverArray = doc.array();
    for (const QJsonValue &val : serverArray) {
        QJsonObject obj = val.toObject();
        QString name = obj["name"].toString();
        int id = obj["id"].toInt();
        serversList->addItem(name, id);
    }

    connect(serversList, QOverload<int>::of(&QComboBox::currentIndexChanged),
            [serversList](int index){
        int id = serversList->itemData(index).toInt();
        QString name = serversList->currentText();
        qDebug() << "Выбран сервер:" << name << "ID:" << id;
    });


    layout->addWidget(label);
    layout->addWidget(serversList);
}
