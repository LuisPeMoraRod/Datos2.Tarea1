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

class MainWindow : public QWidget
{
private slots:
    void handleButton();

private:
    QPushButton *quitBtn;

public:
    MainWindow(QWidget *parent = 0);
    ~MainWindow();

};

class Form : public QWidget{
private:
    QLineEdit *pNewNodeEdit;
    QLineEdit *pFromEdit;
    QLineEdit *pToEdit;
    QLineEdit *pWeightEdit;
    QFormLayout *formLayout;
public:
    Form(QWidget* parent = 0);
    ~Form();
};