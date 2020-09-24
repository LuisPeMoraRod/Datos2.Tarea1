//
// Created by luispedro on 23/9/20.
//

#include "window.h"

MainWindow::MainWindow(QWidget *parent) {
    QPushButton *quitBtn = new QPushButton("Quit", this);
    quitBtn->setGeometry(50, 40, 75, 30);
    connect(quitBtn, &QPushButton::clicked, this, &MainWindow::handleButton);

}
MainWindow::~MainWindow() {
    delete quitBtn;
}

void MainWindow::handleButton()
{
    SocketClient * socket = new SocketClient();
    char* message = "buenos dias";
    char** ptr = &message;
    socket->sendBuffer(ptr);
    std::cout<<"Button pressed "<<std::endl;
}