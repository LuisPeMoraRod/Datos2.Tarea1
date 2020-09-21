//
// Created by luispedro on 21/9/20.
//

#pragma once
#include <string>
#include "Vertex.h"
using namespace std;

class AdjacentNode {
private:
    string name;
    AdjacentNode* pNext;
public:
    AdjacentNode(Vertex* vertex);
    ~AdjacentNode();

    string getName();
    AdjacentNode* getPNext();
    void SetNext(AdjacentNode* pNext);

};


