//
// Created by luispedro on 21/9/20.
//

#include "AdjacentNode.h"

/*!
 * Constructor method
 * @param name
 */
AdjacentNode::AdjacentNode(string name) {
    this->name = name;
}

void AdjacentNode::SetNextNode(AdjacentNode *pNextNode) { this->pNextNode = pNextNode; }

string AdjacentNode::GetName() { return this->name; }

AdjacentNode *AdjacentNode::GetNextNode() { return this->pNextNode; }

AdjacentNode::~AdjacentNode() {};