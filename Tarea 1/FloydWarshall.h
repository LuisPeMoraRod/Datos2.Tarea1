//
// Created by Luis Pedro Morales Rodriguez on 21/9/20.
//

#pragma once

#include "Graph.h"

class FloydWarshall {
private:
    int vertices;
    int **matrix;
    VertexList * pGraph;

    void setDiag(int **matrix);

    void setDistances(int **matrix);

public:
    FloydWarshall(VertexList *pGraph);

    ~FloydWarshall();
};


