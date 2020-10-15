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
#include "SocketServer.h"

using namespace std;

string charToString(char *c, int size);

vector<string> split(const char *str, char c);

string handleMessage(vector<string> message, Vertex **ppVertex, VertexList **ppGraph, AdjacentNode **ppNode);

int main(int argc, char *argv[]) {

    SocketServer *server = new SocketServer();
    server->CreateSocket();
    while (true)
        server->Listen();
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
        } else if (first.compare(second) == 0) {
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