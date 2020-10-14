//
// Created by Luis Pedro Morales on 14/10/20.
//
#include <unistd.h>
#include <stdio.h>
#include <sys/socket.h>
#include <stdlib.h>
#include <netinet/in.h>
#include <string.h>
#define PORT 8080
#include <thread>
#pragma once
using namespace std;

/*!
 * Class that creates server side using socket
 */
class SocketServer {
private:
    int server_fd, new_socket, val_read, opt, addr_len;
    struct sockaddr_in address;
    thread th;
public:
    SocketServer();
    ~SocketServer();
    int CreateSocket();
    void Listen();

};


