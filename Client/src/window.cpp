//
// Created by luispedro on 23/9/20.
//

#include "window.h"
#include <QFormLayout>
#include <QLabel>
#include <QLineEdit>

/*!
 * Constructor method. Create GUI main window
 */
MainWindow::MainWindow(QWidget *parent) {
    pVbox0 = new QVBoxLayout();
    pVbox1 = new QVBoxLayout();
    pVbox2 = new QVBoxLayout();
    pHBox = new QHBoxLayout(this);

    pNewNodeBtn = new QPushButton("Add vertex", this);
    connect(pNewNodeBtn, &QPushButton::clicked, this, &MainWindow::handleNewVertex);
    setBtnColor(pNewNodeBtn);

    pNewEdgeBtn = new QPushButton("Add edge", this);
    connect(pNewEdgeBtn, &QPushButton::clicked, this, &MainWindow::handleNewEdge);
    setBtnColor(pNewEdgeBtn);

    pVbox1->addWidget(pNewNodeBtn);
    pVbox1->addWidget(pNewEdgeBtn);
    pVbox1->addStretch();

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

    pGraphL = new QLabel("Graph: \n");

    pVbox0->addLayout(formLayout);
    pVbox0->addSpacing(vSpacing*4);
    pVbox0->addWidget(pGraphL);
    pVbox0->addStretch();

    pWeightsL = new QLabel("Optimum Weights Matrix", this);
    pWeightMatrix = new QTableWidget(this);
    QTableWidget **ppWMatrix = &pWeightMatrix;
    createMatrix(ppWMatrix);

    pPathsL = new QLabel("Optimum Paths Matrix", this);
    pPathsMatrix = new QTableWidget(this);
    QTableWidget **ppPMatrix = &pPathsMatrix;
    createMatrix(ppPMatrix);

    pVbox2->addWidget(pWeightsL);
    pVbox2->addWidget(pWeightMatrix);
    pVbox2->addSpacing(vSpacing);
    pVbox2->addWidget(pPathsL);
    pVbox2->addWidget(pPathsMatrix);
    pVbox2->addStretch();

    pHBox->addLayout(pVbox0);
    pHBox->addSpacing(hSpacing);
    pHBox->addLayout(pVbox1);
    pHBox->addSpacing(hSpacing * 5);
    pHBox->addLayout(pVbox2);
    pHBox->addStretch();

    setLayout(pHBox);

}

/*!
 * Destructor method
 */
MainWindow::~MainWindow() {
    delete pVbox0;
    delete pVbox1;
    delete pVbox2;
    delete pHBox;

    delete pNewNodeBtn;
    delete pNewEdgeBtn;

    delete pNewNodeEdit;
    delete pFromEdit;
    delete pToEdit;
    delete pWeightEdit;

    delete formLayout;

    QTableWidget **ppMatrix = &pPathsMatrix;
    deleteItems(ppMatrix);
    delete pPathsMatrix;

    delete pPathsL;
    delete pWeightsL;
    delete pGraphL;

    ppMatrix = &pWeightMatrix;
    deleteItems(ppMatrix);
    delete pWeightMatrix;
}

/*!
 * Checks if connection with server was made successfully
 * @param state : int
 * @return boolean
 */
bool MainWindow::IsConnected(int state) {
    if (state < 0){
        QString text = "Error: connection with server failed";
        this->pGraphL->setText(text);
        pGraphL->update();
        return false;
    }
    return true;
}

/*!
 * Communicates with the server via socket to send the new vertex of the graph.
 */
void MainWindow::handleNewVertex() {
    SocketClient *socket = new SocketClient();

    if(IsConnected(socket->getState())) {
        std::string s_message;
        std::string prefix = "V:";
        std::string name = pNewNodeEdit->text().toUtf8().constData();
        pNewNodeEdit->clear();
        s_message.append(prefix);
        s_message.append(name);
        int n = s_message.length();
        char c_message[n + 1];
        strcpy(c_message, s_message.c_str());

        char *message = c_message;
        char **ptr = &message;
        socket->sendBuffer(ptr);
        string bufferReceived = socket->getBuffer();

        updateMatrices(bufferReceived); //update matrices
    }
}

/*!
 * Communicates with the server via socket to send the info for the new edge in the graph
 */
void MainWindow::handleNewEdge() {
    SocketClient *socket = new SocketClient();

    if(IsConnected(socket->getState())) {
        std::string s_message;
        std::string prefix = "E:";
        std::string points = ":";
        std::string toName = pToEdit->text().toUtf8().constData();
        std::string fromName = pFromEdit->text().toUtf8().constData();
        std::string weight = pWeightEdit->text().toUtf8().constData();
        pFromEdit->clear();
        pToEdit->clear();
        pWeightEdit->clear();
        s_message.append(prefix);
        s_message.append(fromName);
        s_message.append(points);
        s_message.append(toName);
        s_message.append(points);
        s_message.append(weight);
        int n = s_message.length();
        char c_message[n + 1];
        strcpy(c_message, s_message.c_str());
        char *message = c_message;
        char **ptr = &message;
        socket->sendBuffer(ptr);
        string bufferReceived = socket->getBuffer();

        updateMatrices(bufferReceived); //update matrices
    }
}

/*!
 * Updates matrices' values
 * @param buffer : string
 */
void MainWindow::updateMatrices(string buffer) {
    vector<string> elements = tokenizeString(buffer, ':');
    if (elements[0].compare("Error") == 0) {
        QString text = QString::fromStdString(elements[0])+":";
        text.append(QString::fromStdString(elements[1]));
        pGraphL->setText(text);
        pGraphL->update();
    } else {
        QTableWidget **ppMatrix = &pWeightMatrix;
        parseToMatrix(elements[0], ppMatrix);

        ppMatrix = &pPathsMatrix;
        parseToMatrix(elements[1], ppMatrix);

        QString text = "Graph: \n\n";
        text.append(QString::fromStdString(elements[2]));
        pGraphL->setText(text);
        pGraphL->update();
    }
}

/*!
 * Set button background to gray color
 * @param button
 */
void MainWindow::setBtnColor(QPushButton *button) {
    QPalette pal = button->palette();
    pal.setColor(QPalette::Button, QColor(Qt::gray));
    button->setAutoFillBackground(true);
    button->setPalette(pal);
    button->update();
}

/*!
 * Configures new QTableWidget object
 * @param ppMatrix
 */
void MainWindow::createMatrix(QTableWidget **ppMatrix) {
    QTableWidget *pMatrix = *ppMatrix;
    pMatrix->windowTitle();
    pMatrix->setWindowTitle("Minimum weights matrix");
    pMatrix->setMinimumSize(500, 300);
    pMatrix->setRowCount(20);
    pMatrix->setColumnCount(20);
    pMatrix->verticalHeader()->setVisible(false);
    pMatrix->horizontalHeader()->setVisible(false);
    pMatrix->setEditTriggers(QAbstractItemView::NoEditTriggers);
    pMatrix->setSelectionBehavior(QAbstractItemView::SelectRows);
    pMatrix->setSelectionMode(QAbstractItemView::SingleSelection);
    pMatrix->setShowGrid(true);
    pMatrix->setStyleSheet("QTableView {selection-background-color: gray;}");
    pMatrix->setGeometry(QApplication::desktop()->screenGeometry());
    setHeadersColor(ppMatrix);
}

/*!
 * Sets each table's cell value
 * @param s_matrix : string
 * @param ppMatrix : QTableWidget **
 */
void MainWindow::parseToMatrix(string s_matrix, QTableWidget **ppMatrix) {
    deleteItems(ppMatrix);
    QTableWidget *pMatrix = *ppMatrix;
    vector<string> rows = tokenizeString(s_matrix, ';');
    this->rows = rows.size();
    for (int i = 0; i < rows.size(); i++) {
        vector<string> columns = tokenizeString(rows[i], '|');
        this->cols = columns.size();
        for (int j = 0; j < columns.size(); j++) {
            QTableWidgetItem *item = new QTableWidgetItem();
            QString text = QString::fromStdString(columns[j]);
            item->setText(text);
            pMatrix->setItem(i, j, item);
            std::cout << columns[j] << std::endl;
        }
    }
    setHeadersColor(ppMatrix);
    pMatrix->update();
}

/*!
 * Sets gray background to the first row and first column of the table
 * @param ppMatrix : QTableWidget
 */
void MainWindow::setHeadersColor(QTableWidget **ppMatrix) {
    QTableWidget *pMatrix = *ppMatrix;
    for (int j = 0; j < cols; j++) {
        pMatrix->item(0, j)->setBackgroundColor(Qt::gray);
    }
    for (int i = 0; i < rows; i++) {
        pMatrix->item(i, 0)->setBackgroundColor(Qt::gray);
    }
}


/*!
 * Deletes all table widgets items
 * @param ppMatrix
 */
void MainWindow::deleteItems(QTableWidget **ppMatrix) {
    QTableWidget *pMatrix = *ppMatrix;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            QTableWidgetItem *item = pMatrix->item(i, j);
            delete item;
        }
    }

}

/*!
 * Tokenizing string received into paths, distances and graph
 * @param s_buffer
 */
vector<string> MainWindow::tokenizeString(string s_buffer, char delim) {
    vector<string> tokens;
    stringstream check1(s_buffer);
    string intermediate;
    while (getline(check1, intermediate, delim)) {
        tokens.push_back(intermediate);
    }
    return tokens;
}


