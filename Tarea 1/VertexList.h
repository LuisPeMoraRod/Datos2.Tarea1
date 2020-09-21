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
    Vertex* GetHead();
    Vertex* GetLast();
    int GetSize();
    void InsertEnd(Vertex* pVertex);
    bool Contains(string name);
    ~VertexList();
};


