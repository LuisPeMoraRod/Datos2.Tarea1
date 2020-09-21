//
// Created by Luis Pedro Morales Rodriguez on 21/9/20.
//

#pragma once
#include "AdjacentNode.h"

class AdjacentNodesList {
private:
    int size;
    AdjacentNode* pHead;
    AdjacentNode* pLast;
public:
    AdjacentNodesList();
    int GetSize();
    AdjacentNode* GetHead();
    AdjacentNode* GetLast();
    void InsertEnd(AdjacentNode* pNode);
    ~AdjacentNodesList();

};


