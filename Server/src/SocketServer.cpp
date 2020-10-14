//
// Created by Luis Pedro Morales on 14/10/20.
//

#include "SocketServer.h"

SocketServer::SocketServer() {
    this->opt = 1;
    this->addr_len = sizeof(address);
}

SocketServer::~SocketServer() {
    delete this;
}

/*!
 * Attempts to create socket attaching it to port 8080. Returns 0 in case of success
 * @return int
 */
int SocketServer::CreateSocket() {
    // Creating socket file descriptor
    if ((server_fd = socket(AF_INET, SOCK_STREAM, 0)) == 0)
    {
        perror("socket failed");
        exit(EXIT_FAILURE);
    }

    // Forcefully attaching socket to the port 8080
    if (setsockopt(server_fd, SOL_SOCKET, SO_REUSEADDR | SO_REUSEPORT,
                   &opt, sizeof(opt)))
    {
        perror("setsockopt");
        exit(EXIT_FAILURE);
    }
    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons( PORT );

    // Forcefully attaching socket to the port 8080
    if (bind(server_fd, (struct sockaddr *)&address,
             sizeof(address))<0)
    {
        perror("bind failed");
        exit(EXIT_FAILURE);
    }
    if (listen(server_fd, 3) < 0)
    {
        perror("listen");
        exit(EXIT_FAILURE);
    }


    return 0;
}

/*!
 * Reads message from the client and sends a response message.
 * @return 0
 */
void SocketServer::Listen() {
    char * buffer[1024]= {0};
    if ((new_socket = accept(server_fd, (struct sockaddr *)&address,
                             (socklen_t*)&addr_len)) < 0)
    {
        perror("accept");
        exit(EXIT_FAILURE);
    }

    char* hello = "Hello from the server";
    val_read = read(new_socket , buffer, 1024);
    printf("%s\n",buffer );
    send(new_socket , hello , strlen(hello) , 0 );
    printf("Hello message sent\n");
}
