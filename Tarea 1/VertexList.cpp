//
// Created by Luis Pedro Morales on 20/9/20.
//

#include "VertexList.h"
/*!
 * Constructor method
 * @param pFirst : Vertex*
 */
VertexList::VertexList() {
    this->size = 0;
    this->pHead = nullptr;
    this->pLast = nullptr;
}

int VertexList::getSize() const {
    return size;
}

Vertex *VertexList::getPHead() const {
    return pHead;
}

Vertex *VertexList::getPLast() const {
    return pLast;
}

/*!
 * Checks if a vertex with an specific name is already contained in the linked list
 * @param name
 * @return true if a vertex with the specified name already exists
 */
bool VertexList::contains(string name) {
    Vertex * ptr = this->pHead;
    for (int i = 0; i<this->size;i++){
        if (name.compare(ptr->getName()) == 0){
            return true;
        }
        ptr = ptr->getPNext();
    }
    return false;
}

/*!
 * Inserts node at the end of the simple linked list
 * @param pVertex : Vertex*
 */
void VertexList::insertEnd(Vertex *pVertex) {
    if (size == 0){
        this->pHead = pVertex;
        this->pLast = pVertex;
        this->size++;
    }else {
        this->pLast->setPNext(pVertex);
        this->pLast = pVertex;
        this->size++;
    }
}

/*!
 * Destructor method
 */
VertexList::~VertexList() {
    delete pHead;
    delete pLast;
}


