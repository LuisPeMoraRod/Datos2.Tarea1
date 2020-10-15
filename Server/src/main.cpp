#include <unistd.h>
#include <stdio.h>
#include <sys/socket.h>
#include <stdlib.h>
#include <netinet/in.h>
#include <string.h>
#include <bits/stdc++.h>

#define PORT 8080

#include <iostream>
#include "graph.h"
#include "floydwarshall.h"
#include "SocketServer.h"

using namespace std;

int main(int argc, char *argv[]) {

    SocketServer *server = new SocketServer();
    server->CreateSocket();
    while (true)
        server->Listen();
    return 0;
}