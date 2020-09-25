//
// Created by luispedro on 23/9/20.
//

#pragma once
#include "stdio.h"
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <string.h>
#define PORT 8080
using namespace std;

class SocketClient {
private:
    int sock, valread,state;
    struct sockaddr_in serv_addr;
    char buffer[2048];
    char* message;
    string charToString(char *c, int size);

public:
    SocketClient();
    ~SocketClient();
    int create();
    void sendBuffer(char** message);
    string getBuffer();
};

