//
// Created by Luis Pedro Morales Rodriguez on 21/9/20.
//

#include "AdjacentNodesList.h"

AdjacentNodesList::AdjacentNodesList() { this->size = 0; }

AdjacentNodesList::~AdjacentNodesList() {}

int AdjacentNodesList::GetSize() { return this->size; }

AdjacentNode *AdjacentNodesList::GetHead() { return this->pHead; }

AdjacentNode *AdjacentNodesList::GetLast() { return this->pLast; }

void AdjacentNodesList::InsertEnd(AdjacentNode *pNode) {
    if (size == 0) {
        this->pHead = pNode;
        this->pLast = pNode;
        this->size++;
    } else {
        this->pLast->SetNextNode(pNode);
        this->pLast = pNode;
        this->size++;
    }
}



