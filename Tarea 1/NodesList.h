//
// Created by luispedro on 21/9/20.
//

#pragma once
#include "AdjacentNode.h"

class NodesList {
private:
    int size;
    AdjacentNode* pHead;
    AdjacentNode* pLast;
public:
    NodesList();
    ~NodesList();

    int getSize() const;

    AdjacentNode *getPHead() const;

    AdjacentNode *getPLast() const;

    void insertEnd(AdjacentNode* pNode);

    bool contains(string name);
};


