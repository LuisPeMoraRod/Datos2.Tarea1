#include <QApplication>
#include <QWidget>
#include <iostream>


#include "Graph.h"


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

    VertexList* list = VertexList::getInstance();
    list->insertEnd(pVertexA);
    std::cout<< "New linked list."<<std::endl;
    std::cout << "First element: " << list->getPHead()->getName() << std::endl;
    std::cout<< "Size: "<<list->getSize()<<std::endl<<std::endl;

    list->insertEnd(pVertexB);
    std::cout<<"Insertion"<<std::endl;
    std::cout << "Last element: " << list->getPLast()->getName() << std::endl;
    std::cout<< "Size: "<<list->getSize()<<std::endl<<std::endl;

    list->insertEnd(pVertexC);
    std::cout<<"Iteration"<<std::endl;
    Vertex* ptr = list->getPHead();
    for (int i = 0; i< list->getSize(); i++){
        std::cout <<"Name: "<< ptr->getName() << " id: "<<ptr->getId()<<std::endl;
        ptr = ptr->getPNext();
    }
    std::cout<<" "<<std::endl;

    AdjacentNode* pNode_a = new AdjacentNode(pVertexA->getName(),10);
    AdjacentNode* pNode_b = new AdjacentNode(pVertexB->getName(),13);

    NodesList* pNodes = pVertexC->getPNodesList();
    pNodes->insertEnd(pNode_a); pNodes->insertEnd(pNode_b);
    AdjacentNode* ptr2 = pNodes->getPHead();
    std::cout<<"Adjacent nodes to C: "<<std::endl;
    for (int i = 0; i<pNodes->getSize();i++){
        std::cout<<ptr2->getName()<<" address: "<<ptr2<<std::endl;
        ptr2 = ptr2->getPNext();
    }

    std::cout<<" "<<std::endl;
    std::cout<<"C address: "<<pVertexC<<std::endl;
    Vertex* pVertex = list->getPVertex(1);
    std::cout<<pNodes->getNode(pVertex->getName())<<std::endl;

    return 0;
}