//
// Created by luispedro on 23/9/20.
//
#pragma once
#include "stdlib.h"
#include <iostream>
#include <string>
#include "SocketClient.h"
#include <bits/stdc++.h>

#include <QMainWindow>
#include <QPushButton>
#include <QCoreApplication>
#include <QApplication>
#include <QWidget>
#include <QFormLayout>
#include <QLineEdit>
#include <QDesktopWidget>
#include <QHeaderView>
#include <QMessageBox>
#include <QTableWidget>

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

    QLabel *pGraphLabel;
    QTableWidget *pWeightMatrix;
    QTableWidget *pPathsMatrix;

    QStringList m_TableHeader;

    string s_graph;
    string s_matrix;

    int vSpacing = 8;
    int hSpacing = 6;
    int w = 180;

    int rows = 0;
    int cols = 0;

    void setBtnColor(QPushButton * button);

    void createMatrix(QTableWidget ** ppMatrix);
    void setHeadersColor(QTableWidget ** ppMatrix);
    vector<string> tokenizeString(string s_buffer, char delim);
    void parseToMatrix(string s_matrix, QTableWidget** ppMatrix);

    void deleteItems(QTableWidget ** ppMatrix);
    void deleteHeaders(QTableWidget **ppMatrix);


public:
    MainWindow(QWidget *parent = 0);

    ~MainWindow();


};
