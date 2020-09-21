//
// Created by luispedro on 21/9/20.
//

#include "AdjacentNode.h"

/*!
 * Constructor method
 * @param vertex : Vertex*
 */
AdjacentNode::AdjacentNode(Vertex *vertex) {
    string name = vertex->GetName();
    this->name = name;
}

void AdjacentNode::SetNextNode(AdjacentNode *pNextNode) { this->pNextNode = pNextNode; }

string AdjacentNode::GetName() { return this->name; }

AdjacentNode *AdjacentNode::GetNextNode() { return this->pNextNode; }

AdjacentNode::~AdjacentNode() {};