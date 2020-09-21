#include <QApplication>
#include <QWidget>
#include <iostream>

#include "Vertex.h"
#include "VertexList.h"

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
    std::cout<< "New linked list."<<std::endl;
    std::cout<<"First element: "<< list.GetHead()->GetName()<<std::endl;
    std::cout<< "Size: "<<list.GetSize()<<std::endl<<std::endl;

    list.InsertEnd(pVertexB);
    std::cout<<"Insertion"<<std::endl;
    std::cout<<"Last element: "<<list.GetLast()->GetName()<<std::endl;
    std::cout<< "Size: "<<list.GetSize()<<std::endl<<std::endl;

    list.InsertEnd(pVertexC);
    std::cout<<"Iteration"<<std::endl;
    Vertex* ptr = list.GetHead();
    for (int i = 0; i< list.GetSize(); i++){
        std::cout<<ptr->GetName()<<std::endl;
        ptr = ptr->GetPNext();
    }
    return 0;
}