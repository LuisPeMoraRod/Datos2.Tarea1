//
// Created by Luis Pedro Morales on 14/10/20.
//

#pragma once
#include "gtest/gtest.h"
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <cstring>
#include "string"
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
    ~SocketServerTest(){
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
    std::thread th(&SocketServer::Listen, server);//Thread to run the server
    char * pMessage = "Testing hello from client";
    char** ppMessage = &pMessage;
    socket->Create(ip_address);
    socket->SendBuffer(ppMessage);
    const char* msgFromClient = server->getPBuffer();
    ASSERT_STREQ(msgFromClient, "Testing hello from client");
    th.join();
}

TEST_F(SocketServerTest, SplitWithComma){
    const char* msg = "Message1,Message2";
    vector<string> actual = server->split(msg, ',');
    int n = actual[0].length();
    char char_array0[n+1];
    strcpy(char_array0, actual[0].c_str());

    n = actual[1].length();
    char char_array1[n+1];
    strcpy(char_array1, actual[1].c_str());

    ASSERT_STREQ(char_array0, "Message1");
    ASSERT_STREQ(char_array1, "Message2");
}

TEST_F(SocketServerTest, CheckTypeFromCharToString){
    char * c = "char to string test";
    string s;
    ASSERT_TRUE(typeid(server->charToString(c,sizeof(c)))==typeid(s));

}

TEST_F(SocketServerTest, CorrectParsingFromCharToString){
    char * char_msg = "char to string test";
    string s_msg = server->charToString(char_msg, strlen(char_msg));
    int n = s_msg.length();
    char char_array[n+1];
    strcpy(char_array, s_msg.c_str());
    ASSERT_STREQ(char_array, "char to string test");
}

TEST_F(SocketServerTest, AddNewVertex){
    const char * request = "V:V1";
    vector<string> new_vertex = server->split(request,':');
    string fw = server->handleMessage(new_vertex);

    string vertex = server->getPGraph()->getPLast()->getName();
    int n = vertex.length();
    char char_vertex [n + 1];
    strcpy(char_vertex, vertex.c_str());

    ASSERT_STREQ(char_vertex, "V1");
}

TEST_F(SocketServerTest, AddExistingVertex){
    const char * request = "V:V1";
    vector<string> new_vertex = server->split(request,':');
    string answer = server->handleMessage(new_vertex);

    vector<string> existing_vertex = server->split(request, ':');
    answer = server-> handleMessage(existing_vertex);
    int n = answer.length();
    char char_ans [n + 1];
    strcpy(char_ans, answer.c_str());

    ASSERT_STREQ(char_ans, "Error: vertex already exists:");
}

TEST_F(SocketServerTest, UnexistentFisrtVrtx){
    const char * request = "E:V2:V3:5";
    vector<string> new_edge = server->split(request, ':');
    string answer = server->handleMessage(new_edge);
    int n = answer.length();
    char char_ans [n + 1];
    strcpy(char_ans, answer.c_str());

    ASSERT_STREQ(char_ans, "Error: first vertex doesn't exist:");
}

TEST_F(SocketServerTest, UnexistentScndVrtx){
    const char * request = "V:V1";
    vector<string> new_vertex = server->split(request,':');
    string answer = server->handleMessage(new_vertex);

    request = "E:V1:V2:5";
    vector<string> new_edge = server->split(request, ':');
    answer = server->handleMessage(new_edge);

    int n = answer.length();
    char char_ans [n + 1];
    strcpy(char_ans, answer.c_str());

    ASSERT_STREQ(char_ans, "Error: second vertex doesn't exist:");
}


TEST_F(SocketServerTest, SameVertex){
    const char * request = "V:V1";
    vector<string> new_vertex = server->split(request,':');
    string answer = server->handleMessage(new_vertex);

    request = "E:V1:V1:5";
    vector<string> new_edge = server->split(request, ':');
    answer = server->handleMessage(new_edge);

    int n = answer.length();
    char char_ans [n + 1];
    strcpy(char_ans, answer.c_str());

    ASSERT_STREQ(char_ans, "Error: both vertices can't be the same:");
}

TEST_F(SocketServerTest, InvalidWeight){
    const char * request = "V:V1";
    vector<string> new_vertex = server->split(request,':');
    string answer = server->handleMessage(new_vertex);

    request = "V:V2";
    new_vertex = server->split(request,':');
    answer = server->handleMessage(new_vertex);

    request = "E:V1:V2:not_int";
    vector<string> new_edge = server->split(request, ':');
    answer = server->handleMessage(new_edge);

    int n = answer.length();
    char char_ans [n + 1];
    strcpy(char_ans, answer.c_str());

    ASSERT_STREQ(char_ans, "Error: couldn't convert weight to integer:");
}

TEST_F(SocketServerTest, AddEdge){
    const char * request = "V:V1";
    vector<string> new_vertex = server->split(request,':');
    string answer = server->handleMessage(new_vertex);

    request = "V:V2";
    new_vertex = server->split(request,':');
    answer = server->handleMessage(new_vertex);

    request = "E:V1:V2:5";
    vector<string> new_edge = server->split(request, ':');
    answer = server->handleMessage(new_edge);

    string adj_node = server->getPGraph()->getPVertex("V1")->getPNodesList()->getPLast()->getName();
    int n = adj_node.length();
    char char_node [n + 1];
    strcpy(char_node, adj_node.c_str());

    int weight = server->getPGraph()->getPVertex("V1")->getPNodesList()->getPLast()->getWeight();
    string s_weight = to_string(weight);
    n = s_weight.length();
    char char_weight[n+1];
    strcpy(char_weight,s_weight.c_str());

    ASSERT_STREQ(char_node, "V2");
    ASSERT_STREQ(char_weight, "5");
}