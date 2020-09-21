//
// Created by Luis Pedro Morales on 21/9/20.
//

#include "AdjacentNode.h"

AdjacentNode::AdjacentNode(Vertex* vertex) {
    this->name = vertex->getName();
}

AdjacentNode::~AdjacentNode() {
    delete pNext;
}

string AdjacentNode::getName() {
    return this->name;
}

AdjacentNode *AdjacentNode::getPNext() {
    return this->pNext;
}

void AdjacentNode::SetNext(AdjacentNode *pNext) {
    this->pNext = pNext;
}
