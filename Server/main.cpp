#include <unistd.h>
#include <stdio.h>
#include <sys/socket.h>
#include <stdlib.h>
#include <netinet/in.h>
#include <string.h>
#include <bits/stdc++.h>

#define PORT 8080

#include <iostream>
#include "graph.h"
#include "floydwarshall.h"

using namespace std;

string charToString(char *c, int size);

vector<string> split(const char *str, char c);

string handleMessage(vector<string> message, Vertex **ppVertex, VertexList **ppGraph, AdjacentNode **ppNode);

int main(int argc, char *argv[]) {
/**
    Vertex *pVertexA = new Vertex("A");
    Vertex *pVertexB = new Vertex("B");
    Vertex *pVertexC = new Vertex("C");
    Vertex *pVertexD = new Vertex("D");
    Vertex *pVertexE = new Vertex("E");*/

    VertexList *pGraph = VertexList::getInstance();
    VertexList **ppGraph = &pGraph;
    Vertex *pVertex;
    Vertex **ppVertex = &pVertex;
    AdjacentNode *pNode;
    AdjacentNode **ppNode = &pNode;

    /**
    pGraph->insertEnd(pVertexA);
    pGraph->insertEnd(pVertexB);
    pGraph->insertEnd(pVertexC);
    pGraph->insertEnd(pVertexD);
    pGraph->insertEnd(pVertexE);

    std::cout << "Vertices" << std::endl;
    Vertex *ptr = pGraph->getPHead();
    for (int i = 0; i < pGraph->getSize(); i++) {
        std::cout << "Name: " << ptr->getName() << " id: " << ptr->getId() << std::endl;
        ptr = ptr->getPNext();
    }
    std::cout << " " << std::endl;

    //Adjacent nodes for A
    AdjacentNode *pNodeA_b = new AdjacentNode(pVertexB->getName(), 2);
    AdjacentNode *pNodeA_c = new AdjacentNode(pVertexC->getName(), 10);
    NodesList *pNodesA = pVertexA->getPNodesList();
    pNodesA->insertEnd(pNodeA_b);
    pNodesA->insertEnd(pNodeA_c);

    //Adjacent nodes for B
    AdjacentNode *pNodeB_d = new AdjacentNode(pVertexD->getName(), 3);
    AdjacentNode *pNodeB_c = new AdjacentNode(pVertexC->getName(), 40);
    NodesList *pNodesB = pVertexB->getPNodesList();
    pNodesB->insertEnd(pNodeB_d);
    pNodesB->insertEnd(pNodeB_c);

     //Adjacent nodes for C
    AdjacentNode *pNodeC_e = new AdjacentNode(pVertexE->getName(), 32);
    NodesList *pNodesC = pVertexC->getPNodesList();
    pNodesC->insertEnd(pNodeC_e);

     // Adjacent nodes for D
    AdjacentNode *pNodeD_b = new AdjacentNode(pVertexB->getName(), 3);
    AdjacentNode *pNodeD_c = new AdjacentNode(pVertexC->getName(), 7);
    NodesList *pNodesD = pVertexD->getPNodesList();
    pNodesD->insertEnd(pNodeD_b);
    pNodesD->insertEnd(pNodeD_c);

     //Adjacent nodes for E
    AdjacentNode *pNodeE_d = new AdjacentNode(pVertexD->getName(), 6);
    AdjacentNode *pNodeE_c = new AdjacentNode(pVertexC->getName(), 32);
    NodesList *pNodesE = pVertexE->getPNodesList();
    pNodesE->insertEnd(pNodeE_d);
    pNodesE->insertEnd(pNodeE_c);

    */


    int server_fd, new_socket, valread;
    struct sockaddr_in address;
    int opt = 1;
    int addrlen = sizeof(address);
    //char buffer[1024] = {0};

    // Creating socket file descriptor
    if ((server_fd = socket(AF_INET, SOCK_STREAM, 0)) == 0) {
        perror("socket failed");
        exit(EXIT_FAILURE);
    }

    // Forcefully attaching socket to the port 8080
    if (setsockopt(server_fd, SOL_SOCKET, SO_REUSEADDR | SO_REUSEPORT,
                   &opt, sizeof(opt))) {
        perror("setsockopt");
        exit(EXIT_FAILURE);
    }
    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons(PORT);

    // Forcefully attaching socket to the port 8080
    if (bind(server_fd, (struct sockaddr *) &address,
             sizeof(address)) < 0) {
        perror("bind failed");
        exit(EXIT_FAILURE);
    }
    if (listen(server_fd, 3) < 0) {
        perror("listen");
        exit(EXIT_FAILURE);
    }
    while(true){
        char buffer[2048] = {0};
        if ((new_socket = accept(server_fd, (struct sockaddr *) &address,
                                 (socklen_t *) &addrlen)) < 0) {
            perror("accept");
            exit(EXIT_FAILURE);
        }
        valread = read(new_socket, buffer, 1024);
        printf("Client says: %s\n", buffer);
        string s_buffer = charToString(buffer, sizeof(buffer));
        vector<string> vector_msg = split(buffer, ':');
        string answer = handleMessage(vector_msg, ppVertex, ppGraph, ppNode);
        const char *c_ans = answer.c_str();
        send(new_socket, c_ans, strlen(c_ans), 0);
        printf("Answer message sent\n");
    }

    return 0;
}

string charToString(char *c, int size) {
    string s;
    for (int i = 0; i < size; i++) {
        s += c[i];
    }
    return s;

}

char *stringToChar(string s) {
    int n = s.length();

    char char_array[n + 1];

    strcpy(char_array, s.c_str());
    return char_array;
}

vector<string> split(const char *str, char c) {
    vector<string> result;

    do {
        const char *begin = str;

        while (*str != c && *str)
            str++;

        result.push_back(string(begin, str));
    } while (0 != *str++);

    return result;
}


string handleMessage(vector<string> message, Vertex **ppVertex, VertexList **ppGraph, AdjacentNode **ppNode) {
    string ans;
    string first, second;
    Vertex *pVertex = *ppVertex;
    VertexList *pGraph = *ppGraph;
    AdjacentNode *pNode = *ppNode;
    if (message[0].compare("V") == 0) {
        if (pGraph->contains(message[1])) {
            return "Error: vertex already exists:";
        }
        pVertex = new Vertex(message[1]);
        pGraph->insertEnd(pVertex);
        std::cout << "insert " << pGraph->getPLast()->getName() << std::endl;
    } else if (message[0].compare("E") == 0) {
        first = message[1];
        second = message[2];
        if (!pGraph->contains(first)) {
            ans = "Error: first vertex doesn't exist:";
            return ans;
        } else if (!pGraph->contains(second)) {
            ans = "Error: second vertex doesn't exist:";
            return ans;
        }else if(first.compare(second) == 0){
            ans = "Error: both vertices can't be the same:";
            return ans;
        }

        try {
            pVertex = pGraph->getPVertex(first);
            int weight = stoi(message[3]);
            pNode = new AdjacentNode(second, weight);
            NodesList *nodeList = pVertex->getPNodesList();
            nodeList->insertEnd(pNode);
        } catch (std::exception) {
            ans = "Error: couldn't convert weight to integer:";//integer required
            return ans;
        }

    }
    FloydWarshall *pMatrix = new FloydWarshall(pGraph);
    ans = pMatrix->getMatrices();
    return ans;
}