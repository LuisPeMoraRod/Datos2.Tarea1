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
    setBtnColor(pNewNodeBtn);

    pNewEdgeBtn = new QPushButton("Add edge", this);
    connect(pNewEdgeBtn, &QPushButton::clicked, this, &MainWindow::handleNewEdge);
    setBtnColor(pNewEdgeBtn);

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

    pPathsMatrix = new QTableWidget(this);
    QTableWidget **ppPMatrix = &pPathsMatrix;
    createMatrix(ppPMatrix);

    pWeightMatrix = new QTableWidget(this);
    QTableWidget **ppWMatrix = &pWeightMatrix;
    createMatrix(ppWMatrix);


    pHBox->addLayout(formLayout);
    pHBox->addSpacing(hSpacing);
    pHBox->addLayout(pVbox);
    pHBox->addSpacing(hSpacing);
    pHBox->addWidget(pPathsMatrix);
    pHBox->addSpacing(hSpacing);
    pHBox->addWidget(pWeightMatrix);
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

    QTableWidget **ppMatrix = &pPathsMatrix;
    deleteItems(ppMatrix);
    delete pPathsMatrix;


    ppMatrix= &pWeightMatrix;
    deleteItems(ppMatrix);
    delete pWeightMatrix;
}

/*!
 * Communicates with the server via socket to send the new vertex of the graph.
 */
void MainWindow::handleNewVertex() {
    SocketClient *socket = new SocketClient();

    std::string s_message;
    std::string prefix = "V:";
    std::string name = pNewNodeEdit->text().toUtf8().constData();
    s_message.append(prefix);
    s_message.append(name);
    int n = s_message.length();
    char c_message[n + 1];
    strcpy(c_message, s_message.c_str());

    char *message = c_message;
    char **ptr = &message;
    socket->sendBuffer(ptr);
    string bufferReceived = socket->getBuffer();
    std::cout<<bufferReceived<<std::endl;
}

/*!
 * Communicates with the server via socket to send the info for the new edge in the graph
 */
void MainWindow::handleNewEdge() {
    SocketClient *socket = new SocketClient();

    std::string s_message;
    std::string prefix = "E:";
    std::string points = ":";
    std::string toName = pToEdit->text().toUtf8().constData();
    std::string fromName = pFromEdit->text().toUtf8().constData();
    std::string weight = pWeightEdit->text().toUtf8().constData();
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
    vector<string> elements = tokenizeString(bufferReceived,':');
    QTableWidget ** ppMatrix = &pWeightMatrix;
    parseToMatrix(elements[0],ppMatrix);
    std::cout<<"first matrix"<<elements[0]<<std::endl;

}



void MainWindow::setBtnColor(QPushButton *button) {
    QPalette pal = button->palette();
    pal.setColor(QPalette::Button, QColor(Qt::gray));
    button->setAutoFillBackground(true);
    button->setPalette(pal);
    button->update();
}

void MainWindow::createMatrix(QTableWidget **ppMatrix) {
    QTableWidget *pMatrix = *ppMatrix;
    pMatrix->windowTitle();
    pMatrix->setWindowTitle("Minimum weights matrix");
    pMatrix->setMinimumSize(400, 300);
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

    //insert data
    //pMatrix->setItem(0, 1, new QTableWidgetItem("Hello"));

}

void MainWindow::parseToMatrix(string s_matrix, QTableWidget** ppMatrix) {
    deleteItems(ppMatrix);
    QTableWidget* pMatrix = *ppMatrix;
    std::cout<<"debug"<<std::endl;
    vector<string> rows = tokenizeString(s_matrix, ';');
    this->rows = rows.size();
    for(int i = 0; i < rows.size(); i++){
        vector<string> columns = tokenizeString(rows[i], '|');
        this->cols = columns.size();
        for(int j = 0; j < columns.size(); j++){
            QTableWidgetItem *item = new QTableWidgetItem();
            QString text = QString::fromStdString(columns[j]);
            item->setText(text);
            pMatrix->setItem(i,j,item);
            std::cout<<columns[j]<<std::endl;
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
 * Deletes vertical and horizontal headers
 * @param ppMatrix
 */
void MainWindow::deleteHeaders(QTableWidget **ppMatrix){
    QTableWidget *pMatrix = *ppMatrix;
    int col = pMatrix->columnCount();
    int row = pMatrix->rowCount();
    for (int j = 0; j < col; j++) {
        QTableWidgetItem *item = pMatrix->item(0,j);
        delete item;
    }
    for (int i = 0; i < row; i++) {
        QTableWidgetItem *item = pMatrix->item(i,0);
        delete item;
    }
}

/*!
 * Deletes all table widgets items
 * @param ppMatrix
 */
void MainWindow::deleteItems(QTableWidget **ppMatrix) {
    QTableWidget *pMatrix = *ppMatrix;
    for (int i = 0; i < rows; i++){
        for (int j = 0; j < cols; j++){
            QTableWidgetItem *item = pMatrix->item(i,j);
            delete item;
        }
    }

}

/*!
 * Tokenizing string received into paths, distances and graph
 * @param s_buffer
 */
vector<string> MainWindow::tokenizeString(string s_buffer, char delim) {
    vector <string> tokens;
    stringstream check1(s_buffer);
    string intermediate;
    while(getline(check1, intermediate, delim))
    {
        tokens.push_back(intermediate);
    }
    return tokens;
}


