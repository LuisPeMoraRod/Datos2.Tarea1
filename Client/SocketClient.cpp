//
// Created by luispedro on 23/9/20.
//

#include <string>
#include "SocketClient.h"

SocketClient::SocketClient() {
    sock = 0;
    buffer[1024] = {0};
    state = create();
}

int SocketClient::create() {
    if ((sock = socket(AF_INET, SOCK_STREAM, 0)) < 0)
    {
        printf("\n Socket creation error \n");
        return -1;
    }

    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(PORT);

    // Convert IPv4 and IPv6 addresses from text to binary form
    if(inet_pton(AF_INET, "127.0.0.1", &serv_addr.sin_addr)<=0)
    {
        printf("\nInvalid address/ Address not supported \n");
        return -1;
    }

    if (connect(sock, (struct sockaddr *) &serv_addr, sizeof(serv_addr)) < 0)
    {
        printf("\nConnection Failed \n");
        return -1;
    }
    return 0;
}

void SocketClient::sendBuffer(char** message) {
    send(sock , *message , strlen(*message) , 0 );
    printf("Message sent from the server\n");
    valread = read( sock , buffer, 1024);
    //printf("%s\n",buffer );
}

SocketClient::~SocketClient() {
    delete this;
}

string SocketClient::getBuffer() {
    string s_buffer = this->charToString(buffer, 2048);
    return s_buffer;
}

string SocketClient::charToString(char *c, int size) {
    string s;
    for (int i = 0; i < size; i++) {
        s += c[i];
    }
    return s;
}
