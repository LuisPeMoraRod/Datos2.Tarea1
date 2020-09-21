//
// Created by Luis Pedro Morales Rodriguez on 21/9/20.
//

#include "AdjacentNodesList.h"

AdjacentNodesList::AdjacentNodesList() { this->size = 0; }

AdjacentNodesList::~AdjacentNodesList() {}

int AdjacentNodesList::GetSize() { this->size; }

AdjacentNode *AdjacentNodesList::GetHead() { this->pHead; }

AdjacentNode *AdjacentNodesList::GetLast() { this->pLast; }

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



