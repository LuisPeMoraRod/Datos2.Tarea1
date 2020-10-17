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
        return -1;// Socket creation error
    }
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(PORT);

    // Convert IPv4 and IPv6 addresses from text to binary form
    if(inet_pton(AF_INET, ip_address, &serv_addr.sin_addr)<=0)
    {
        return -1; //Invalid address/ Address not supported
    }

    if (connect(sock, (struct sockaddr *) &serv_addr, sizeof(serv_addr)) < 0)
    {
        return -2;//Connection failed
    }
    return 0;
}


/*!
 * Sends message to server
 * @param message : char**
 */
void SocketClient::SendBuffer(char** message) {
    send(sock , *message , strlen(*message) , 0 );
    printf("Message sent from the server\n");
    valread = read( sock , buffer, 1024);
    printf(buffer);
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
