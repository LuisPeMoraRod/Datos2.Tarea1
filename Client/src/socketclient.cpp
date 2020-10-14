//
// Created by luispedro on 23/9/20.
//

#include <string>
#include "socketclient.h"

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
 * Attempts to create socket. Returns 0 if succeeded or -1 if failed
 * @return state : int
 */
int SocketClient::Create(const char * ip_address) {
    if ((sock = socket(AF_INET, SOCK_STREAM, 0)) < 0)
    {
        printf("\n Socket creation error \n");
        return -1;
    }
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(PORT);

    // Convert IPv4 and IPv6 addresses from text to binary form
    if(inet_pton(AF_INET, ip_address, &serv_addr.sin_addr)<=0)
    {
        printf("\nInvalid address/ Address not supported \n");
        return -1;
    }

    if (connect(sock, (struct sockaddr *) &serv_addr, sizeof(serv_addr)) < 0)
    {
        printf("\nConnection Failed \n");
        return -2;
    }
    return 0;
}

/*!
 * Sends message to server
 * @param message : char**
 */
void SocketClient::sendBuffer(char** message) {
    send(sock , *message , strlen(*message) , 0 );
    printf("Message sent from the server\n");
    valread = read( sock , buffer, 1024);
}

/*!
 * Destructor method
 */
SocketClient::~SocketClient() {
    delete this;
}

/*!
 * buffer getter
 * @return s_buffer : string
 */
string SocketClient::getBuffer() {
    string s_buffer = this->charToString(buffer, 2048);
    return s_buffer;
}

/*!
 * Parse to string from char type
 * @param c : char*
 * @param size : int
 * @return s : string
 */
string SocketClient::charToString(char *c, int size) {
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
int SocketClient::getState() const {
    return state;
}
