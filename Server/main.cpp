#include <unistd.h>
#include <stdio.h>
#include <sys/socket.h>
#include <stdlib.h>
#include <netinet/in.h>
#include <string.h>

#define PORT 8080

#include <iostream>
#include "graph.h"
#include "floydwarshall.h"

int main(int argc, char *argv[]) {

    Vertex *pVertexA = new Vertex("A");
    Vertex *pVertexB = new Vertex("B");
    Vertex *pVertexC = new Vertex("C");
    Vertex *pVertexD = new Vertex("D");
    Vertex *pVertexE = new Vertex("E");

    VertexList *pGraph = VertexList::getInstance();

    pGraph->insertEnd(pVertexA);
    pGraph->insertEnd(pVertexB);
    pGraph->insertEnd(pVertexC);
    pGraph->insertEnd(pVertexD);
    pGraph->insertEnd(pVertexE);

    std::cout << "Vertices" << std::endl;
    Vertex *ptr = pGraph->getPHead();
    for (int i = 0; i < pGraph->getSize(); i++) {
        std::cout << "Name: " << ptr->getName() << " id: " << ptr->getId() << std::endl;
        ptr = ptr->getPNext();
    }
    std::cout << " " << std::endl;

    /*
     * Adjacent nodes for A
     */
    AdjacentNode *pNodeA_b = new AdjacentNode(pVertexB->getName(), 2);
    AdjacentNode *pNodeA_c = new AdjacentNode(pVertexC->getName(), 10);
    NodesList *pNodesA = pVertexA->getPNodesList();
    pNodesA->insertEnd(pNodeA_b);
    pNodesA->insertEnd(pNodeA_c);

    /*
     * Adjacent nodes for B
     */
    AdjacentNode *pNodeB_d = new AdjacentNode(pVertexD->getName(), 3);
    AdjacentNode *pNodeB_c = new AdjacentNode(pVertexC->getName(), 40);
    NodesList *pNodesB = pVertexB->getPNodesList();
    pNodesB->insertEnd(pNodeB_d);
    pNodesB->insertEnd(pNodeB_c);

    /*
     * Adjacent nodes for C
     */
    AdjacentNode *pNodeC_e = new AdjacentNode(pVertexE->getName(), 32);
    NodesList *pNodesC = pVertexC->getPNodesList();
    pNodesC->insertEnd(pNodeC_e);

    /*
     * Adjacent nodes for D
     */
    AdjacentNode *pNodeD_b = new AdjacentNode(pVertexB->getName(), 3);
    AdjacentNode *pNodeD_c = new AdjacentNode(pVertexC->getName(), 7);
    NodesList *pNodesD = pVertexD->getPNodesList();
    pNodesD->insertEnd(pNodeD_b);
    pNodesD->insertEnd(pNodeD_c);

    /*
     * Adjacent nodes for E
     */
    AdjacentNode *pNodeE_d = new AdjacentNode(pVertexD->getName(), 6);
    AdjacentNode *pNodeE_c = new AdjacentNode(pVertexC->getName(), 32);
    NodesList *pNodesE = pVertexE->getPNodesList();
    pNodesE->insertEnd(pNodeE_d);
    pNodesE->insertEnd(pNodeE_c);

    FloydWarshall *pMatrix = new FloydWarshall(pGraph);
    pMatrix->printMatrix();


    int server_fd, new_socket, valread;
    struct sockaddr_in address;
    int opt = 1;
    int addrlen = sizeof(address);
    //char buffer[1024] = {0};
    char *hello = "Hello from server";

    // Creating socket file descriptor
    if ((server_fd = socket(AF_INET, SOCK_STREAM, 0)) == 0) {
        perror("socket failed");
        exit(EXIT_FAILURE);
    }

    // Forcefully attaching socket to the port 8080
    if (setsockopt(server_fd, SOL_SOCKET, SO_REUSEADDR | SO_REUSEPORT,
                   &opt, sizeof(opt))) {
        perror("setsockopt");
        exit(EXIT_FAILURE);
    }
    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons(PORT);

    // Forcefully attaching socket to the port 8080
    if (bind(server_fd, (struct sockaddr *) &address,
             sizeof(address)) < 0) {
        perror("bind failed");
        exit(EXIT_FAILURE);
    }
    if (listen(server_fd, 3) < 0) {
        perror("listen");
        exit(EXIT_FAILURE);
    }
    for (int i = 0; i < 3; i++) {
        char buffer[1024] = {0};
        if ((new_socket = accept(server_fd, (struct sockaddr *) &address,
                                 (socklen_t *) &addrlen)) < 0) {
            perror("accept");
            exit(EXIT_FAILURE);
        }
        valread = read(new_socket, buffer, 1024);
        printf("%s\n", buffer);
        send(new_socket, hello, strlen(hello), 0);
        printf("Hello message sent\n");
    }
    return 0;
}