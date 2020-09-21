//
// Created by Luis Pedro Morales Rodriguez on 21/9/20.
//

#include "NodesList.h"

NodesList::NodesList() {
    this->size = 0;
    this->pHead = nullptr;
    this->pLast = nullptr;
}

NodesList::~NodesList() {
    delete pLast;
    delete pHead;
}

int NodesList::getSize() const {
    return size;
}

AdjacentNode *NodesList::getPHead() const {
    return pHead;
}

AdjacentNode *NodesList::getPLast() const {
    return pLast;
}

void NodesList::insertEnd(AdjacentNode *pNode) {
    if(size == 0){
        this->pHead = pNode;
        this->pLast = pNode;
        this->size++;
    }
    else{
        this->pLast->SetNext(pNode);
        this->pLast = pNode;
        this->size++;
    }
}

bool NodesList::contains(string name) {
    AdjacentNode * ptr = this->pHead;
    for (int i = 0; i<this->size;i++){
        if (name.compare(ptr->getName()) == 0){
            return true;
        }
        ptr = ptr->getPNext();
    }
    return false;
}
