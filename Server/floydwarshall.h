//
// Created by Luis Pedro Morales Rodriguez on 21/9/20.
//

#pragma once
#include <string>
#include <limits>
#include "graph.h"
using namespace std;

class FloydWarshall {
private:
    int vertices;
    int **distMatrix;
    string **pathsMatrix;
    VertexList * pGraph;

    void setDiag(int **matrix);
    void setDiag(string **matrix);

    void setDistances(int **matrix);
    void setPaths(string **matrix);

    string setHeaders();
    void executeFW();

    string **getPathsMatrix() const;

public:
    FloydWarshall(VertexList *pGraph);

    ~FloydWarshall();

    void printMatrix();
    string getMatrices();

    int **getDistMatrix() const;


    string getGraphRepresentation(string **ppMsg);
};


