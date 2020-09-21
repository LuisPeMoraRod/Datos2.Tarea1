//
// Created by Luis Pedro Morales Rodriguez on 21/9/20.
//

#pragma once
#include <string>
#include "Vertex.h"
using namespace std;

class AdjacentNode {
private:
    string name;
    AdjacentNode* pNextNode;
public:
    AdjacentNode(string name);
    void SetNextNode(AdjacentNode* pNextNode);
    string GetName();
    AdjacentNode* GetNextNode();
    ~AdjacentNode();
};


