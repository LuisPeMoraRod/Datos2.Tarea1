//
// Created by luispedro on 23/9/20.
//

#include "window.h"
#include <QFormLayout>
#include <QLabel>
#include <QLineEdit>

MainWindow::MainWindow(QWidget *parent) {
    pVbox = new QVBoxLayout();
    pHBox = new QHBoxLayout(this);

    pNewNodeBtn = new QPushButton("Add vertex", this);
    connect(pNewNodeBtn, &QPushButton::clicked, this, &MainWindow::handleNewVertex);

    pNewEdgeBtn = new QPushButton("Add edge", this);
    connect(pNewEdgeBtn, &QPushButton::clicked, this, &MainWindow::handleNewEdge);

    pVbox->addWidget(pNewNodeBtn);
    pVbox->addWidget(pNewEdgeBtn);
    pVbox->addStretch();


    pNewNodeEdit = new QLineEdit(this);
    pNewNodeEdit->setFixedWidth(w);

    pFromEdit = new QLineEdit(this);
    pFromEdit->setFixedWidth(w);

    pToEdit = new QLineEdit(this);
    pToEdit->setFixedWidth(w);

    pWeightEdit = new QLineEdit(this);
    pWeightEdit->setFixedWidth(w);

    formLayout = new QFormLayout;
    formLayout->setLabelAlignment(Qt::AlignLeft | Qt::AlignVCenter);
    formLayout->addRow("New vertex:", pNewNodeEdit);
    formLayout->addRow("New edge from:", pFromEdit);
    formLayout->addRow("New edge to:", pToEdit);
    formLayout->addRow("Weight:", pWeightEdit);

    pHBox->addLayout(formLayout);
    pHBox->addSpacing(hSpacing);
    pHBox->addLayout(pVbox);
    pHBox->addStretch();

    setLayout(pHBox);

}
MainWindow::~MainWindow() {
    delete pVbox;
    delete pHBox;

    delete pNewNodeBtn;
    delete pNewEdgeBtn;

    delete pNewNodeEdit;
    delete pFromEdit;
    delete pToEdit;
    delete pWeightEdit;

    delete formLayout;

}

/*!
 * Comunicates with the server via socket to send the new vertex of the graph.
 */
void MainWindow::handleNewVertex()
{
    SocketClient * socket = new SocketClient();
    std::string s_message;
    std::string prefix = "V:";
    std::string name = pNewNodeEdit->text().toUtf8().constData();
    s_message.append(prefix);
    s_message.append(name);
    int n = s_message.length();
    char c_message [n+1];
    strcpy(c_message,s_message.c_str());

    char* message = c_message;
    char** ptr = &message;
    socket->sendBuffer(ptr);
    std::cout<<"Button pressed "<<std::endl;
}

/*!
 * Comunicates with the server via socket to send the info for the new edge in the graph
 */
 void MainWindow::handleNewEdge() {
    SocketClient * socket = new SocketClient();
    char* message = "buenos dias";
    char** ptr = &message;
    socket->sendBuffer(ptr);
    std::cout<<"Button pressed "<<std::endl;
 }
