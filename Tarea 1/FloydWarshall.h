//
// Created by Luis Pedro Morales Rodriguez on 21/9/20.
//

#pragma once
#include <string>
#include <limits>
#include "Graph.h"
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

    void sort();

public:
    FloydWarshall(VertexList *pGraph);

    ~FloydWarshall();

    void printMatrix();

    int **getDistMatrix() const;

    string **getPathsMatrix() const;
};


