//
// Created by Luis Pedro Morales on 14/10/20.
//

#include "socketclient.h"
#include "gtest/gtest.h"
#include <unistd.h>
#include <stdio.h>
#include <sys/socket.h>
#include <stdlib.h>
#include <netinet/in.h>
#include <string.h>
#include "string"
#define PORT 8080
#include <thread>

/*!
 * Class that creates server side using socket
 */
class Server {
private:
    int server_fd, new_socket, val_read, opt, addr_len;
    struct sockaddr_in address;
    thread th;

public:
    Server();
    ~Server();
    int CreateSocket();
    void Listen();
};
Server::Server() {
    this->opt = 1;
    this->addr_len = sizeof(address);
}

Server::~Server() {
    delete this;
}


/*!
 * Attempts to create socket attaching it to port 8080. Returns 0 in case of success
 * @return int
 */
int Server::CreateSocket() {
    // Creating socket file descriptor
    if ((server_fd = socket(AF_INET, SOCK_STREAM, 0)) == 0)
    {
    }

    // Forcefully attaching socket to the port 8080
    if (setsockopt(server_fd, SOL_SOCKET, SO_REUSEADDR | SO_REUSEPORT,
                   &opt, sizeof(opt)))
    {
    }
    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons( PORT );

    // Forcefully attaching socket to the port 8080
    if (bind(server_fd, (struct sockaddr *)&address,
             sizeof(address))<0)
    {
    }
    if (listen(server_fd, 3) < 0)
    {
    }


    return 0;
}

/*!
 * Reads message from the client and sends a response message.
 * @return 0
 */
void Server::Listen()
{
    char * buffer[1024]= {0};
    new_socket = accept(server_fd, (struct sockaddr *)&address,
                             (socklen_t*)&addr_len);

    char* hello = "Hello from the server";
    val_read = read(new_socket , buffer, 1024);
    send(new_socket , hello , strlen(hello) , 0 );
}


class SocketClientTest : public ::testing::Test{
protected:
    Server* server;
    SocketClient * socket;
    const char * ip_address;
    void SetUp() override{
        server = new Server();
        socket = new SocketClient();
        ip_address = "127.0.0.1";
    }
    void TearDown() override{
    }

};

TEST_F(SocketClientTest, ServerNotRunning){
    ASSERT_EQ(socket->Create(ip_address),-2);
}

TEST_F(SocketClientTest, HandleInvalidIp){
    ASSERT_EQ(socket->Create("address"),-1);
    ASSERT_EQ(socket->Create("127.0.0"),-1);
}

TEST_F(SocketClientTest, SuccessfulConnection){
    server->CreateSocket();
    ASSERT_EQ(socket->Create(ip_address),0);
}

TEST_F(SocketClientTest, CommunicationWithServer){
    server->CreateSocket();
    std::thread th(&Server::Listen, server);//Thread to run the server
    socket->Create(ip_address);
    char * pMessage = "Testing hello from client";
    char** ppMessage = &pMessage;
    socket->SendBuffer(ppMessage);
    const char* msgFromServer = socket->GetBufferChar();
    ASSERT_STREQ(msgFromServer, "Hello from the server");
    th.join();
}


TEST_F(SocketClientTest, CheckTypeFromCharToString){
    char * c = "char to string test";
    string s;
    ASSERT_TRUE(typeid(socket->CharToString(c,sizeof(c)))==typeid(s));

}

TEST_F(SocketClientTest, CorrectParsingFromCharToString){
    char * char_msg = "char to string test";
    string s_msg = socket->CharToString(char_msg, strlen(char_msg));
    int n = s_msg.length();
    char char_array[n+1];
    strcpy(char_array, s_msg.c_str());
    ASSERT_STREQ(char_array, "char to string test");
}