//
// Created by luispedro on 23/9/20.
//

#pragma once
#include "cstdio"
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <cstring>
#include "string"
#include <iostream>
#define PORT 8080
using namespace std;
/*!
 * Class that creates a client for the server in port 8080 using sockets
 */
class SocketClient {
private:
    int sock, valread,state;
    struct sockaddr_in serv_addr;
    char buffer[2048];
    char* message;
    const char* ip_address;


public:
    SocketClient();
    ~SocketClient();
    int Create(const char * ip_address);
    void SendBuffer(char** message);
    string GetBuffer();
    const char* GetBufferChar();
    int GetState() const;
    string CharToString(char *c, int size);
};

