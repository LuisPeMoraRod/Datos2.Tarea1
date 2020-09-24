//
// Created by luispedro on 23/9/20.
//
#pragma once

#include <QMainWindow>
#include <QPushButton>
#include <QCoreApplication>
#include <QApplication>
#include "stdlib.h"
#include <iostream>
#include "SocketClient.h"
#include <QWidget>
#include <QFormLayout>
#include <QLineEdit>
#include <string>

using namespace std;

class MainWindow : public QWidget {
private slots:

    void handleNewVertex();

    void handleNewEdge();

private:
    QPushButton *pNewNodeBtn;
    QPushButton *pNewEdgeBtn;

    QLineEdit *pNewNodeEdit;
    QLineEdit *pFromEdit;
    QLineEdit *pToEdit;
    QLineEdit *pWeightEdit;
    QFormLayout *formLayout;

    QVBoxLayout *pVbox;
    QHBoxLayout *pHBox;

    int vSpacing = 8;
    int hSpacing = 6;
    int w = 180;

public:
    MainWindow(QWidget *parent = 0);

    ~MainWindow();

};
