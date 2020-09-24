//
// Created by luispedro on 23/9/20.
//

#include "window.h"
#include <QFormLayout>
#include <QLabel>
#include <QLineEdit>

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

Form::Form(QWidget *parent) : QWidget(parent){
    pNewNodeEdit = new QLineEdit(this);
    pFromEdit = new QLineEdit(this);
    pToEdit = new QLineEdit(this);
    pWeightEdit = new QLineEdit(this);

    formLayout = new QFormLayout;
    formLayout->setLabelAlignment(Qt::AlignLeft | Qt::AlignVCenter);
    formLayout->addRow("New Node:", pNewNodeEdit);
    formLayout->addRow("New edge from:", pFromEdit);
    formLayout->addRow("New edge to:", pToEdit);
    formLayout->addRow("Weight:", pWeightEdit);

    setLayout(formLayout);

}

Form::~Form(){
    delete pNewNodeEdit;
    delete pFromEdit;
    delete pToEdit;
    delete pWeightEdit;
    delete formLayout;
}