//
// Created by luispedro on 21/9/20.
//

#include "FloydWarshall.h"

FloydWarshall::FloydWarshall(VertexList *pGraph) {
    this->pGraph = pGraph;
    this->vertices = pGraph->getSize();
    this->matrix = new int *[vertices];
    for (int i = 0; i < vertices; i++)
        matrix[i] = new int[vertices];

}

FloydWarshall::~FloydWarshall() {

}

void FloydWarshall::setDiag(int **matrix) {
    for (int i = 0; i < this->vertices; i++) {
        matrix[i][i] = 0;
    }
}

void FloydWarshall::setDistances(int **matrix) {
    Vertex* pVertex;Vertex* pVertexTemp;
    for (int i = 0; i < vertices; i++) {
        pVertex = this->pGraph->getPVertex(i);
        NodesList* pNodeListTemp = pVertex->getPNodesList();
        string nodeName;
        AdjacentNode* pNodeTemp;
        for (int j = 0; j < vertices; j++){
            pVertexTemp = this->pGraph->getPVertex(j);
            nodeName = pVertexTemp->getName();
            pNodeTemp = pNodeListTemp->getNode(nodeName);
        }

    }
}




