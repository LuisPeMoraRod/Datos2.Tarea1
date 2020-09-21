//
// Created by Luis Pedro Morales Rodriguez on 20/9/20.
//

#pragma once
#include <string>

using namespace std;

class Vertex{
private:
    string name;
    Vertex * pNext;

public:
    Vertex(string name);
    string getName();
    Vertex * getPNext();
    void setPNext(Vertex* pVertex);
    ~Vertex();

};

