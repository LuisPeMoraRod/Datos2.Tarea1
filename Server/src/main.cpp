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

    VertexList *pGraph = VertexList::getInstance();
    VertexList **ppGraph = &pGraph;
    Vertex *pVertex;
    Vertex **ppVertex = &pVertex;
    AdjacentNode *pNode;
    AdjacentNode **ppNode = &pNode;

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