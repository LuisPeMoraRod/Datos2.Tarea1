//
// Created by Luis Pedro Morales Rodriguez on 20/9/20.
//

#include "graph.h"

/*!
 * Adjacent node constructor method
 * @param name
 * @param weight
 */
AdjacentNode::AdjacentNode(string name, int weight) {
    this->name = name;
    this->weight = weight;
}
/*!
 * Destructor method
 */
AdjacentNode::~AdjacentNode() {
    delete this;
}

//
//Setters and getters
//
string AdjacentNode::getName() const {
    return this->name;
}

AdjacentNode *AdjacentNode::getPNext() const {
    return this->pNext;
}

void AdjacentNode::SetNext(AdjacentNode *pNext) {
    this->pNext = pNext;
}

int AdjacentNode::getWeight() const {
    return weight;
}

void AdjacentNode::setWeight(int weight) {
    AdjacentNode::weight = weight;
}


/*!
 * NodesList constructor method
 */
NodesList::NodesList() {
    this->size = 0;
    this->pHead = nullptr;
    this->pLast = nullptr;
}

/*!
 * Destructor method
 */
NodesList::~NodesList() {
    delete pLast;
    delete pHead;
    delete this;
}

int NodesList::getSize() const {
    return size;
}

AdjacentNode *NodesList::getPHead() const {
    return pHead;
}

AdjacentNode *NodesList::getPLast() const {
    return pLast;
}

/*!
 * Inserts node at the end of the list or edits node if it already exists
 * @param pNode : AdjacentNode *
 */
void NodesList::insertEnd(AdjacentNode *pNode) {
    string name = pNode->getName();
    int w = pNode->getWeight();
    if (size == 0) {
        this->pHead = pNode;
        this->pLast = pNode;
        this->size++;
    } else if (!contains(name)){
        this->pLast->SetNext(pNode);
        this->pLast = pNode;
        this->size++;
    }else{
        AdjacentNode* pNodeOld = getNode(name);
        pNodeOld->setWeight(w);
    }
}

/*!
 * Checks if a node with a specific name exists in the list
 * @param name  : string
 * @return contains : boolean
 */
bool NodesList::contains(string name) {
    AdjacentNode *ptr = this->pHead;
    for (int i = 0; i < this->size; i++) {
        if (name.compare(ptr->getName()) == 0) {
            return true;
        }
        ptr = ptr->getPNext();
    }
    return false;
}

/*!
 * Searches for vertex with specific name and returns pointer pointing to it
 * @param name : string
 * @return pNode : AdjacentNode *
 */
AdjacentNode *NodesList::getNode(string name) {
    AdjacentNode *pNode = this->pHead;
    for (int i = 0; i < this->size; i++) {
        if (name.compare(pNode->getName()) == 0) {
            return pNode;
        }
        pNode = pNode->getPNext();
    }
    return nullptr;
}

/*!
 * Constructor method
 * @param name : string
 */
Vertex::Vertex(string name) : name(name) {
    this->pNodesList = new NodesList();
    this->id = amount;
    this->amount++;
}

/*!
 * Destructor method
 */
Vertex::~Vertex() {
    delete this;
}

int Vertex::amount = 0;

string Vertex::getName() { return this->name; }

void Vertex::setPNext(Vertex *pVertex) { this->pNext = pVertex; }

Vertex *Vertex::getPNext() const { return this->pNext; }

NodesList *Vertex::getPNodesList() const { return this->pNodesList; }

int Vertex::getId() const { return id; }


/*!
 * Private constructor method
 * @param pFirst : Vertex*
 */
VertexList::VertexList() {
    this->pHead = nullptr;
    this->pLast = nullptr;
}

int VertexList::size = 0;
/*!
 *Singleton instantiation
 */
VertexList *VertexList::instance = 0;

/*!
 * Get the only instance
 * @return instance : VertexList
 */
VertexList *VertexList::getInstance() {
    if (!instance) {
        instance = new VertexList();
        return instance;
    }
    return instance;
}

int VertexList::getSize() const {
    return size;
}

Vertex *VertexList::getPHead() const {
    return pHead;
}

Vertex *VertexList::getPLast() const {
    return pLast;
}

/*!
 * Checks if a vertex with an specific name is already contained in the linked list
 * @param name
 * @return true if a vertex with the specified name already exists
 */
bool VertexList::contains(string name) {
    Vertex *ptr = this->pHead;
    for (int i = 0; i < this->size; i++) {
        if ( ptr->getName().compare(name)== 0) {
            return true;
        }
        ptr = ptr->getPNext();
    }
    return false;
}

/*!
 * Inserts node at the end of the simple linked list
 * @param pVertex : Vertex*
 */
void VertexList::insertEnd(Vertex *pVertex) {
    if (size == 0) {
        this->pHead = pVertex;
        this->pLast = pVertex;
        this->size++;
    } else {
        this->pLast->setPNext(pVertex);
        this->pLast = pVertex;
        this->size++;
    }

}

/*!
 * Destructor method
 */
VertexList::~VertexList() {
    delete pHead;
    delete pLast;
    delete instance;
    delete this;
}

/*!
 * Searches for vertex with specific id and returns pointer pointing to it
 * @param id : int
 * @return pVertex : Vertex*
 */
Vertex* VertexList::getPVertex(int id) {
    Vertex* pVertex = pHead;
    for (int i = 0; i < this->size; i++){
        if (pVertex->getId() == id)
            return pVertex;
        pVertex = pVertex->getPNext();
    }
    return nullptr;
}

/*!
 * Searches for vertex with specific name and returns pointer pointing to it
 * @param id : int
 * @return pVertex : Vertex*
 */
Vertex *VertexList::getPVertex(string name) {
    Vertex *ptr = this->pHead;
    for (int i = 0; i < this->size; i++) {
        if ( ptr->getName().compare(name)== 0) {
            return ptr;
        }
        ptr = ptr->getPNext();
    }
    return nullptr;
}
