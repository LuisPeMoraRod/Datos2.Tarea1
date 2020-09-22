#include <QApplication>
#include <QWidget>
#include <iostream>
#include "Graph.h"
#include "FloydWarshall.h"

int main(int argc, char *argv[]) {
/*
    QApplication app(argc, argv);

    QWidget window;

    window.resize(250, 150);
    window.setWindowTitle("Simple example");
    window.show();

    return app.exec();*/

    Vertex *  pVertexA = new Vertex("A");
    Vertex *  pVertexB = new Vertex("B");
    Vertex *  pVertexC = new Vertex("C");
    Vertex *  pVertexD = new Vertex("D");
    Vertex *  pVertexE = new Vertex("E");

    VertexList* pGraph = VertexList::getInstance();

    pGraph->insertEnd(pVertexA);
    pGraph->insertEnd(pVertexB);
    pGraph->insertEnd(pVertexC);
    pGraph->insertEnd(pVertexD);
    pGraph->insertEnd(pVertexE);

    std::cout<<"Vertices"<<std::endl;
    Vertex* ptr = pGraph->getPHead();
    for (int i = 0; i < pGraph->getSize(); i++){
        std::cout <<"Name: "<< ptr->getName() << " id: "<<ptr->getId()<<std::endl;
        ptr = ptr->getPNext();
    }
    std::cout<<" "<<std::endl;

    /*
     * Adjacent nodes for A
     */
    AdjacentNode* pNodeA_b = new AdjacentNode(pVertexB->getName(),2);
    AdjacentNode* pNodeA_c = new AdjacentNode(pVertexC->getName(),10);
    NodesList* pNodesA = pVertexA->getPNodesList();
    pNodesA->insertEnd(pNodeA_b); pNodesA->insertEnd(pNodeA_c);

    /*
     * Adjacent nodes for B
     */
    AdjacentNode* pNodeB_d = new AdjacentNode(pVertexD->getName(),3);
    AdjacentNode* pNodeB_c = new AdjacentNode(pVertexC->getName(),40);
    NodesList* pNodesB = pVertexB->getPNodesList();
    pNodesB->insertEnd(pNodeB_d); pNodesB->insertEnd(pNodeB_c);

    /*
     * Adjacent nodes for C
     */
    AdjacentNode* pNodeC_e = new AdjacentNode(pVertexE->getName(),32);
    NodesList* pNodesC = pVertexC->getPNodesList();
    pNodesC->insertEnd(pNodeC_e);

    /*
     * Adjacent nodes for D
     */
    AdjacentNode* pNodeD_b = new AdjacentNode(pVertexB->getName(),3);
    AdjacentNode* pNodeD_c = new AdjacentNode(pVertexC->getName(),7);
    NodesList* pNodesD = pVertexD->getPNodesList();
    pNodesD->insertEnd(pNodeD_b); pNodesD->insertEnd(pNodeD_c);

    /*
     * Adjacent nodes for E
     */
    AdjacentNode* pNodeE_d = new AdjacentNode(pVertexD->getName(),6);
    AdjacentNode* pNodeE_c = new AdjacentNode(pVertexC->getName(),32);
    NodesList* pNodesE = pVertexE->getPNodesList();
    pNodesE->insertEnd(pNodeE_d); pNodesE->insertEnd(pNodeE_c);

    FloydWarshall* pMatrix = new FloydWarshall(pGraph);
    pMatrix->printMatrix();

    delete pVertexA;
    delete pVertexB;
    delete pVertexC;
    delete pVertexD;
    delete pVertexE;

    delete pNodeA_b;
    delete pNodeA_c;
    delete pNodeB_d;
    delete pNodeB_c;
    delete pNodeC_e;
    delete pNodeD_b;
    delete pNodeD_c;
    delete pNodeE_c;
    delete pNodeE_d;

    delete pMatrix;
    return 0;
}