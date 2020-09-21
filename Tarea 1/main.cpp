#include <QApplication>
#include <QWidget>
#include <iostream>

#include "Vertex.h"
#include "VertexList.h"
#include "AdjacentNode.h"

int main(int argc, char *argv[]) {
/*
    QApplication app(argc, argv);

    QWidget window;

    window.resize(250, 150);
    window.setWindowTitle("Simple example");
    window.show();

    return app.exec();*/
    Vertex vertex_a ("A");
    Vertex vertex_b ("B");
    Vertex vertex_c ("C");

    Vertex *  pVertexA = &vertex_a;
    Vertex *  pVertexB = &vertex_b;
    Vertex *  pVertexC = &vertex_c;

    VertexList list;
    list.insertEnd(pVertexA);
    std::cout<< "New linked list."<<std::endl;
    std::cout << "First element: " << list.getPHead()->getName() << std::endl;
    std::cout<< "Size: "<<list.getSize()<<std::endl<<std::endl;

    list.insertEnd(pVertexB);
    std::cout<<"Insertion"<<std::endl;
    std::cout << "Last element: " << list.getPLast()->getName() << std::endl;
    std::cout<< "Size: "<<list.getSize()<<std::endl<<std::endl;

    list.insertEnd(pVertexC);
    std::cout<<"Iteration"<<std::endl;
    Vertex* ptr = list.getPHead();
    for (int i = 0; i< list.getSize(); i++){
        std::cout << ptr->getName() << std::endl;
        ptr = ptr->getPNext();
    }
    std::cout<<" "<<std::endl;

    AdjacentNode* pNode_a = new AdjacentNode(pVertexA);
    AdjacentNode* pNode_b = new AdjacentNode(pVertexB);


    delete pVertexA;
    delete pVertexB;
    delete pVertexC;
    delete pNode_a;
    delete pNode_b;
    return 0;
}