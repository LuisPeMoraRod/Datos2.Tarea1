//
// Created by luispedro on 20/9/20.
//

#include "VertexList.h"

VertexList::VertexList(Vertex *pFirst) {
    this->pHead = pFirst;
    this->pLast = pFirst;
    this->size = 1;
}

Vertex *VertexList::GetHead() { return this->pHead; }

Vertex *VertexList::GetLast() { return this->pLast; }

int VertexList::GetSize() { return this->size; }

void VertexList::InsertEnd(Vertex *pVertex) {
    this->pLast->SetPNext(pVertex);
    this->pLast = pVertex;
    this->size++;
}

VertexList::~VertexList() {}


