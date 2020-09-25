//
// Created by luispedro on 21/9/20.
//

#include "floydwarshall.h"
#include <iostream>

FloydWarshall::FloydWarshall(VertexList *pGraph) {
    this->pGraph = pGraph;
    this->vertices = pGraph->getSize();
    this->distMatrix = new int *[vertices];
    this->pathsMatrix = new string *[vertices];
    for (int i = 0; i < vertices; i++) {
        distMatrix[i] = new int[vertices];
        pathsMatrix[i] = new string[vertices];
    }
    setDistances(distMatrix);
    setDiag(distMatrix);

    setPaths(pathsMatrix);
    setDiag(pathsMatrix);

    sort();
}

FloydWarshall::~FloydWarshall() {
    for (int i = 0; i < vertices; i++)
        delete distMatrix[i];
    delete distMatrix;

    for (int i = 0; i < vertices; i++)
        delete pathsMatrix[i];

    delete pathsMatrix;
    delete this;
}

void FloydWarshall::setDiag(int **matrix) {
    for (int i = 0; i < this->vertices; i++) {
        matrix[i][i] = 0;
    }
}

void FloydWarshall::setDiag(string **matrix) {
    for (int i = 0; i < this->vertices; i++) {
        matrix[i][i] = "-";
    }
}

void FloydWarshall::setDistances(int **matrix) {
    Vertex *pVertex;
    Vertex *pVertexTemp;
    for (int i = 0; i < vertices; i++) {
        pVertex = this->pGraph->getPVertex(i);
        NodesList *pNodeListTemp = pVertex->getPNodesList();
        string nodeName;
        AdjacentNode *pNodeTemp;
        for (int j = 0; j < vertices; j++) {
            pVertexTemp = this->pGraph->getPVertex(j);
            nodeName = pVertexTemp->getName();
            pNodeTemp = pNodeListTemp->getNode(nodeName);
            int value = pNodeListTemp->contains(nodeName) ? pNodeTemp->getWeight() : 100000000;
            matrix[i][j] = value;
        }

    }
}

void FloydWarshall::setPaths(string **matrix) {
    Vertex *pVertex;
    for (int i = 0; i < vertices; i++) {
        for (int j = 0; j < vertices; j++) {
            pVertex = pGraph->getPVertex(j);
            matrix[i][j] = pVertex->getName();
        }
    }
}

void FloydWarshall::printMatrix() {
    for (int i = 0; i < vertices; i++) {
        for (int j = 0; j < vertices; j++) {
            int value = distMatrix[i][j] == 100000000 ? -1 : distMatrix[i][j];
            std::cout << value << "\t\t\t";
        }
        std::cout << "\n";
    }
    std::cout << "\n\n";

    for (int i = 0; i < vertices; i++) {
        for (int j = 0; j < vertices; j++) {
            std::cout << pathsMatrix[i][j] << "\t\t\t";
        }
        std::cout << "\n";
    }

}

void FloydWarshall::sort() {
    Vertex *pVertex;
    for (int k = 0; k < vertices; k++) {
        for (int i = 0; i < vertices; i++) {
            for (int j = 0; j < vertices; j++) {
                if (distMatrix[i][j] > (distMatrix[i][k] + distMatrix[k][j])) {
                    distMatrix[i][j] = distMatrix[i][k] + distMatrix[k][j];
                    pVertex = pGraph->getPVertex(k);
                    pathsMatrix[i][j] = pVertex->getName();
                }
            }
        }
    }
}



string FloydWarshall::getMatrices() {
    string msg;
    for (int k = 0; k < 2; k++) {
        for (int i = -1; i < this->vertices; i++) {
            if (i < 0)
                msg .append(setHeaders());
            else {
                for (int j = -1; j < this->vertices; j++) {
                    if (j < 0) {
                        msg.append(pGraph->getPVertex(i)->getName());
                        msg.append("|");
                    } else {
                        string value;
                        if (k == 0) {
                            value = distMatrix[i][j] == 100000000 ? "-" : to_string(distMatrix[i][j]);
                            msg.append(value);

                        } else if (k == 1) {
                            value = pathsMatrix[i][j];
                            msg.append(value);
                        }
                        msg.append("|");
                    }
                }
                msg.append(";");
            }
        }
        msg.append(":");
    }
    string *pMsg = &msg;
    string ** ppMsg = &pMsg;
    msg.append(getGraphRepresentation(ppMsg));
    std::cout<<msg<<std::endl;
    return msg;
}

string FloydWarshall::setHeaders() {
    string headers = string();
    headers.append(" ");
    headers.append("|");
    for (int i = 0; i < this->vertices; i++) {
        headers.append(pGraph->getPVertex(i)->getName());
        headers.append("|");
    }
    headers.append(";");
    return headers;
}

string FloydWarshall::getGraphRepresentation(string ** ppMsg){
    string* pMsg = * ppMsg;
    string nameVrtx;
    NodesList* pNodesList;
    AdjacentNode* pNode;
    for(int i = 0; i < vertices; i++){
        nameVrtx = pGraph->getPVertex(i)->getName();
        pMsg->append(nameVrtx);
        pMsg->append(" ==> ");
        pNodesList = pGraph->getPVertex(i)->getPNodesList();
        pNode = pNodesList->getPHead();
        for(int j = 0; j < pNodesList->getSize(); j++){
            pMsg->append("("+pNode->getName()+","+to_string(pNode->getWeight())+") ");
            if (j<pNodesList->getSize()-1){
                pMsg->append("- ");
            }
            pNode = pNode->getPNext();
        }
        pMsg->append("\n");
    }
    pMsg->append(":");
}







