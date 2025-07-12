#include "mainwindow.h"

#include <QComboBox>
#include <QFile>
#include <QJsonArray>
#include <QJsonDocument>
#include <QJsonObject>
#include <QNetworkAccessManager>
#include <QNetworkRequest>
#include <QNetworkReply>
#include <QLabel>
#include <QMainWindow>
#include <QVBoxLayout>
#include <QDebug>

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent){
    createWindow();
}

void MainWindow::onServersDownloaded(QNetworkReply* reply) {
    if (reply->error() != QNetworkReply::NoError) {
        qWarning() << "Ошибка загрузки:" << reply->errorString();
        reply->deleteLater();
        return;
    }

    QByteArray jsonData = reply->readAll();
    reply->deleteLater();

    QJsonDocument doc = QJsonDocument::fromJson(jsonData);
    if (!doc.isArray()) {
        qWarning() << "Неверный формат JSON (ожидался массив)";
        return;
    }

    serversList->clear();
    for (const QJsonValue &v : doc.array()) {
        auto obj = v.toObject();
        QString name = obj.value("name").toString();
        int id = obj.value("id").toInt();
        serversList->addItem(name, id);
    }

    if (serversList->count() > 0)
        serversList->setCurrentIndex(0);

    connect(serversList, QOverload<int>::of(&QComboBox::currentIndexChanged),
        this, [this](int index){
            int id = serversList->itemData(index).toInt();
            QString name = serversList->currentText();
            qDebug() << "Выбран:" << name << "ID:" << id;
        });
}

void MainWindow::createWindow() {
    this->setFixedSize(400, 600);
    this->setWindowTitle("BUBLYAASH VPN");
    this->setStyleSheet("background-image: url(':/media/background.png');"
                        "background-repeat: no-repeat;"
                        "background-position: center;");

    QNetworkAccessManager *nam = new QNetworkAccessManager(this);
    connect(nam, &QNetworkAccessManager::finished,
            this, &MainWindow::onServersDownloaded);
    QUrl url("https://raw.githubusercontent.com/BUBLYAASH/bublyaash-vpn/master/servers.json");
    nam->get(QNetworkRequest(url));

    QWidget *widget = new QWidget(this);
    this->setCentralWidget(widget);

    QVBoxLayout *layout = new QVBoxLayout(widget);
    layout->setAlignment(Qt::AlignCenter);

    QLabel *label = new QLabel("BUBLYAASH");
    label->setStyleSheet("font-size: 24px; color: white;");
    label->setAlignment(Qt::AlignTop);

    serversList = new QComboBox(this);
    serversList->setStyleSheet("background: transparent; border: none; color: white;");
    serversList->setFixedSize(200, 50);

    // QFile file(":/servers.json");
    // if (!file.open(QIODevice::ReadOnly)) {
    //     qDebug() << "File open error";
    //     return;
    // }

    // QByteArray data = file.readAll();
    // file.close();
    //
    // QJsonDocument doc = QJsonDocument::fromJson(data);
    // if (!doc.isArray()) {
    //     qDebug() << "JSON is not an array";
    //     return;
    // }

    layout->addWidget(label);
    layout->addWidget(serversList);
}
