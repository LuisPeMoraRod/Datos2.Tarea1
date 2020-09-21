//
// Created by luispedro on 21/9/20.
//

#pragma once
#include "AdjacentNode.h"

class AdjNodesList {
private:
    int size;
    AdjacentNode* pHead;
    AdjacentNode* pLast;
public:
    AdjNodesList();
    ~AdjNodesList();
    int GetSize();
};


