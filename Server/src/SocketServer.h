//
// Created by Luis Pedro Morales on 14/10/20.
//
#include <unistd.h>
#include <stdio.h>
#include <sys/socket.h>
#include <stdlib.h>
#include <netinet/in.h>
#include <string.h>
#include <bits/stdc++.h>
#include <iostream>
#include "graph.h"
#include "floydwarshall.h"
#define PORT 8080
#pragma once
using namespace std;

/*!
 * Class that creates server side using socket
 */
class SocketServer {
private:
    VertexList *pGraph;
    Vertex *pVertex;
    AdjacentNode *pNode;
    char* pBuffer;

    int server_fd, new_socket, val_read, opt, addr_len;
    struct sockaddr_in address;
    thread th;
public:
    SocketServer();
    ~SocketServer();
    int CreateSocket();
    int Listen();
    string charToString(char *c, int size);
    vector<string> split(const char *str, char c);
    string handleMessage(vector<string> message);

    char *getPBuffer() const;
};


