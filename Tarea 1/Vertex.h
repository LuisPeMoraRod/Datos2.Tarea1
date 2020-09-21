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
    string GetName();
    Vertex * GetPNext();
    void SetPNext(Vertex* pVertex);
    ~Vertex();

};

