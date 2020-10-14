//
// Created by Luis Pedro Morales Rodriguez on 20/9/20.
//

#pragma once

#include <string>
#include <stdlib.h>
#include<iostream>
using namespace std;

/*!
 * Class for adjacent nodes for specific nodes
 */
class AdjacentNode {
private:
    string name;
    int weight;
    AdjacentNode *pNext;
public:
    AdjacentNode(string name, int weight);

    ~AdjacentNode();

    string getName() const;

    AdjacentNode *getPNext() const;

    int getWeight() const;

    void SetNext(AdjacentNode *pNext);

    void setWeight(int weight);
};

/*!
 * Linked list for all the adjacent nodes for a specific vertex
 */
class NodesList {
private:
    int size;
    AdjacentNode *pHead;
    AdjacentNode *pLast;
public:
    NodesList();

    ~NodesList();

    int getSize() const;

    AdjacentNode *getPHead() const;

    AdjacentNode *getPLast() const;

    void insertEnd(AdjacentNode *pNode);

    bool contains(string name);

    AdjacentNode* getNode(string name);
};

/*!
 * Class for vertexes of the graph
 */
class Vertex {
private:
    static int amount;
    int id;
    string name;
    Vertex *pNext;
    NodesList *pNodesList;

public:
    Vertex(string name);

    ~Vertex();

    string getName();

    Vertex *getPNext() const;

    void setPNext(Vertex *pVertex);

    NodesList *getPNodesList() const;

    int getId() const;

};

/*!
 * Simple linked list class. Uses Vertex objects as its nodes.
 */
class VertexList {
private:
    static int size;
    Vertex *pHead;
    Vertex *pLast;

    VertexList();

    static VertexList *instance;

public:
    static VertexList *getInstance();

    void insertEnd(Vertex *pVertex);

    bool contains(string name);

    ~VertexList();

    int getSize() const;

    Vertex *getPHead() const;

    Vertex *getPLast() const;

    Vertex* getPVertex(int id);
    Vertex * getPVertex(string name);
};