//
// Created by Luis Pedro Morales on 14/10/20.
//

#pragma once
#include "gtest/gtest.h"
#include "cstdio"
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <cstring>
#include "string"
#include <iostream>
#include "SocketServer.h"
#define PORT 8080
using namespace std;

/*!
 * Class that creates a client for the server in port 8080 using sockets
 */
class SocketClient{
private:
    int sock, valread,state;
    struct sockaddr_in serv_addr;
    char buffer[2048];
    char* message;
    const char* ip_address;
    string CharToString(char *c, int size);

public:
    SocketClient();
    ~SocketClient();
    int Create(const char * ip_address);
    void SendBuffer(char** message);
    string GetBuffer();
    const char* GetBufferChar();
    int GetState() const;
};


/*!
 * Constructor method
 */
SocketClient::SocketClient() {
    sock = 0;
    buffer[1024] = {0};
    ip_address= "127.0.0.1";
    state = Create(ip_address);
}

/*!
 * Destructor method
 */
SocketClient::~SocketClient() {
    delete this;
}

/*!
 * Attempts to create socket. Returns 0 if succeeded or -1 if failed
 * @return state : int
 */
int SocketClient::Create(const char * ip_address) {
    if ((sock = socket(AF_INET, SOCK_STREAM, 0)) < 0)
    {
        return -1;
    }
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(PORT);

    // Convert IPv4 and IPv6 addresses from text to binary form
    if(inet_pton(AF_INET, ip_address, &serv_addr.sin_addr)<=0)
    {
        return -1;
    }

    if (connect(sock, (struct sockaddr *) &serv_addr, sizeof(serv_addr)) < 0)
    {
        return -2;
    }
    return 0;
}


/*!
 * Sends message to server
 * @param message : char**
 */
void SocketClient::SendBuffer(char** message) {
    send(sock , *message , strlen(*message) , 0 );
    valread = read( sock , buffer, 1024);
}

/*!
 * buffer getter
 * @return s_buffer : string
 */
string SocketClient::GetBuffer() {
    string s_buffer = this->CharToString(buffer, 2048);
    return s_buffer;
}

const char * SocketClient ::GetBufferChar() {
    return this->buffer;
}

/*!
 * Parse to string from char type
 * @param c : char*
 * @param size : int
 * @return s : string
 */
string SocketClient::CharToString(char *c, int size) {
    string s;
    for (int i = 0; i < size; i++) {
        s += c[i];
    }
    return s;
}

/*!
 * state getter
 * @return state : int
 */
int SocketClient::GetState() const {
    return state;
}

class SocketServerTest : public :: testing::Test{
public:
    SocketServer* server;
    SocketClient * socket;
    const char * ip_address;
    void SetUp() override{
        server = new SocketServer();
        socket = new SocketClient();
        ip_address = "127.0.0.1";
    }
    void TearDown() override{
    }
};

TEST_F(SocketServerTest, SocketCreatedSuccessfully){
    ASSERT_EQ(server->CreateSocket(),0);
}
TEST_F(SocketServerTest, ServerNotCreated){
    ASSERT_EQ(server->Listen(),-1);
}
TEST_F(SocketServerTest, SendResponse){
    server->CreateSocket();
    socket->Create(ip_address);
    std::thread th(&SocketServer::Listen, server);//Thread to run the server
    char * pMessage = "Testing hello from client";
    char** ppMessage = &pMessage;
    socket->SendBuffer(ppMessage);
    const char* msgFromClient = server->getPBuffer();
    ASSERT_STREQ(msgFromClient, "Testing hello from client");
    th.join();
}
