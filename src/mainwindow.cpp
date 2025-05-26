#include "mainwindow.h"

#include <QHBoxLayout>
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
    QVBoxLayout *layout = new QVBoxLayout();
    QHBoxLayout *header = new QHBoxLayout();
    QVBoxLayout *body = new QVBoxLayout();

    layout->addLayout(header);
    layout->addLayout(body);
}
