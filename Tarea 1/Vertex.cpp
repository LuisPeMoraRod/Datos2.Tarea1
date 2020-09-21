//
// Created by Luis Pedro Morales Rodriguez on 20/9/20.
//

#include "Vertex.h"

Vertex::Vertex(string name) : name(name) {

}

string Vertex::GetName() {
    return this->name;
}

void Vertex::SetPNext(Vertex* pVertex) { this->pNext = pVertex; }
Vertex* Vertex :: GetPNext(){return this -> pNext;}
Vertex::~Vertex() {}


