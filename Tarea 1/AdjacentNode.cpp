//
// Created by Luis Pedro Morales on 21/9/20.
//

#include "AdjacentNode.h"

AdjacentNode::AdjacentNode(Vertex *vertex) {
    this->name = vertex->GetName();
}

AdjacentNode::~AdjacentNode() {}

string AdjacentNode::GetName() {
    return this->name;
}

AdjacentNode *AdjacentNode::GetNext() {
    return this->pNext;
}

void AdjacentNode::SetNext(AdjacentNode *pNext) {
    this->pNext = pNext;
}
