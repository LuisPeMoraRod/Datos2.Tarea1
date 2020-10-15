//
// Created by Luis Pedro Morales on 14/10/20.
//

#include "SocketServer.h"

SocketServer::SocketServer() {
    this->opt = 1;
    this->addr_len = sizeof(address);
    pGraph = VertexList::getInstance();
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
 */
void SocketServer::Listen() {
    char buffer[2048] = {0};
    if ((new_socket = accept(server_fd, (struct sockaddr *) &address,
                             (socklen_t *) &addr_len)) < 0) {
        perror("accept");
        exit(EXIT_FAILURE);
    }
    val_read = read(new_socket, buffer, 1024);//read message from client (assigned to buffer)
    printf("Client says: %s\n", buffer);

    string s_buffer = charToString(buffer, sizeof(buffer));// buffer to string
    vector<string> vector_msg = split(buffer, ':');//tokenize message

    string answer = handleMessage(vector_msg);

    const char *c_ans = answer.c_str(); //parse answer to char
    send(new_socket, c_ans, strlen(c_ans), 0);//send reply to client

    printf("Answer message sent\n");
}

/*!
 * Parse char array to string
 * @param c : char *
 * @param size : int
 * @return s : string
 */
string SocketServer::charToString(char *c, int size) {
    string s;
    for (int i = 0; i < size; i++) {
        s += c[i];
    }
    return s;
}

/*!
 * Tokenize char array into string vector, splitting the array using the char c delimiter
 * @param str : const char *
 * @param c : char
 * @return result : vector<string>
 */
vector<string> SocketServer::split(const char *str, char c) {
    vector<string> result;

    do {
        const char *begin = str;

        while (*str != c && *str)
            str++;

        result.push_back(string(begin, str));
    } while (0 != *str++);

    return result;
}

string SocketServer::handleMessage(vector<string> message) {
    string ans, first, second;
    if (message[0].compare("V") == 0) {
        if (pGraph->contains(message[1])) {
            return "Error: vertex already exists:";
        }
        pVertex = new Vertex(message[1]);
        pGraph->insertEnd(pVertex);
        std::cout << "insert " << pGraph->getPLast()->getName() << std::endl;
    } else if (message[0].compare("E") == 0) {
        first = message[1];
        second = message[2];
        if (!pGraph->contains(first)) {
            ans = "Error: first vertex doesn't exist:";
            return ans;
        } else if (!pGraph->contains(second)) {
            ans = "Error: second vertex doesn't exist:";
            return ans;
        }else if(first.compare(second) == 0){
            ans = "Error: both vertices can't be the same:";
            return ans;
        }

        try {
            pVertex = pGraph->getPVertex(first);
            int weight = stoi(message[3]);
            pNode = new AdjacentNode(second, weight);
            NodesList *nodeList = pVertex->getPNodesList();
            nodeList->insertEnd(pNode);
        } catch (std::exception) {
            ans = "Error: couldn't convert weight to integer:";//integer required
            return ans;
        }

    }
    FloydWarshall *pMatrix = new FloydWarshall(pGraph);
    ans = pMatrix->getMatrices();
    return ans;
}
