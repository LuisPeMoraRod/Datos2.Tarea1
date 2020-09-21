//
// Created by Luis Pedro Morales Rodriguez on 20/9/20.
//

#include "Vertex.h"

Vertex::Vertex(string name) : name(name) {}

string Vertex::getName() { return this->name; }

void Vertex::setPNext(Vertex *pVertex) { this->pNext = pVertex; }

Vertex *Vertex::getPNext() { return this->pNext; }

Vertex::~Vertex() {}

