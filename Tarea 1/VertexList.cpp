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
}

Vertex *VertexList::GetHead() { return this->pHead; }

Vertex *VertexList::GetLast() { return this->pLast; }

int VertexList::GetSize() { return this->size; }

/*!
 * Checks if a vertex with an specific name is already contained in the linked list
 * @param name
 * @return true if a vertex with the specified name already exists
 */
bool VertexList::Contains(string name) {
    Vertex * ptr = this->pHead;
    for (int i = 0; i<this->size;i++){
        if (name.compare(ptr->GetName())==0){
            return true;
        }
        ptr = ptr->GetPNext();
    }
    return false;
}

/*!
 * Inserts node at the end of the simple linked list
 * @param pVertex : Vertex*
 */
void VertexList::InsertEnd(Vertex *pVertex) {
    if (size == 0){
        this->pHead = pVertex;
        this->pLast = pVertex;
        this->size++;
    }else {
        this->pLast->SetPNext(pVertex);
        this->pLast = pVertex;
        this->size++;
    }
}

/*!
 * Destructor method
 */
VertexList::~VertexList() {}


