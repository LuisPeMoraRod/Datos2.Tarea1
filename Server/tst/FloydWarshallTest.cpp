//
// Created by Luis Pedro Morales on 16/10/20.
//
#include "graph.h"
#include "floydwarshall.h"
#include "gtest/gtest.h"

class FloydWarshallTest : public ::testing::Test {
public:
    VertexList *pGraph;
    Vertex *pVertex;
    AdjacentNode *pNode;
    FloydWarshall *floyd_w;

    void SetUp() override {
        pGraph = VertexList::getInstance();
        pVertex = new Vertex("A");
        pGraph->insertEnd(pVertex);
        pVertex = new Vertex("B");
        pGraph->insertEnd(pVertex);
        pVertex = new Vertex("C");
        pGraph->insertEnd(pVertex);

        pVertex = pGraph->getPVertex("A");
        pNode = new AdjacentNode("B", 5);
        NodesList *nodeList = pVertex->getPNodesList();
        nodeList->insertEnd(pNode);

        pNode = new AdjacentNode("C", 7);
        nodeList = pVertex->getPNodesList();
        nodeList->insertEnd(pNode);

        pVertex = pGraph->getPVertex("B");
        pNode = new AdjacentNode("C", 1);
        nodeList = pVertex->getPNodesList();
        nodeList->insertEnd(pNode);

        pVertex = pGraph->getPVertex("C");
        pNode = new AdjacentNode("B", 2);
        nodeList = pVertex->getPNodesList();
        nodeList->insertEnd(pNode);

        floyd_w = new FloydWarshall(pGraph);
    }


};

TEST_F(FloydWarshallTest, GetGraph) {
    string message = " ";
    string *pMsg = &message;
    string **ppMsg = &pMsg;
    string graph = floyd_w->getGraphRepresentation(ppMsg);
    int n = graph.length();
    char char_array[n + 1];
    strcpy(char_array, graph.c_str());
    char *expected = " A ==> (B,5) - (C,7) \nB ==> (C,1) \nC ==> (B,2) \n:";
    ASSERT_STREQ(char_array, expected);
}

TEST_F(FloydWarshallTest, SetDiagonalStr) {
    bool isZero = true;
    string **ppMatrixstr = new string *[3];
    for (int i = 0; i < 3; i++) {
        ppMatrixstr[i] = new string[3];
    }
    floyd_w->setDiag(ppMatrixstr);

    for (int i = 0; i < 3; i++) {
        if (ppMatrixstr[i][i] != "-")
            isZero = false;
    }

    ASSERT_TRUE(isZero);
}

TEST_F(FloydWarshallTest, SetDiagonal0) {
    bool isZero = true;
    int **ppMatrix = new int *[3];
    for (int i = 0; i < 3; i++) {
        ppMatrix[i] = new int[3];
    }

    floyd_w->setDiag(ppMatrix);

    for (int i = 0; i < 3; i++) {
        if (ppMatrix[i][i] != 0)
            isZero = false;
    }

    ASSERT_TRUE(isZero);
}

TEST_F(FloydWarshallTest, HandleMatrices) {
    string ans = floyd_w->getMatrices();
    int n = ans.length();
    char char_array[n + 1];
    strcpy(char_array, ans.c_str());
    char *expected = " |A|B|C|;A|0|5|6|;B|-|0|1|;C|-|2|0|;: |A|B|C|;A|-|B|B|;B|-|-|C|;C|-|B|-|;:A ==> (B,5) - (C,7) \nB ==> (C,1) \nC ==> (B,2) \n: |A|B|C|;A|0|5|6|;B|-|0|1|;C|-|2|0|;: |A|B|C|;A|-|B|B|;B|-|-|C|;C|-|B|-|;:A ==> (B,5) - (C,7) \nB ==> (C,1) \nC ==> (B,2) \n:";
    ASSERT_STREQ(char_array, expected);
}