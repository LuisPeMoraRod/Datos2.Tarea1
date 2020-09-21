//
// Created by luispedro on 20/9/20.
//

#pragma once
#include "Vertex.h"
/*!
 * Simple linked list class. Uses Vertex objects as its nodes.
 */
class VertexList {
private:
    int size;
    Vertex* pHead;
    Vertex* pLast;
public:
    VertexList();
    void insertEnd(Vertex* pVertex);
    bool contains(string name);
    ~VertexList();

    int getSize() const;

    Vertex *getPHead() const;

    Vertex *getPLast() const;
};


