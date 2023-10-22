#ifndef NODE_H
#define NODE_H
#include <iostream>
#include <vector>

using namespace std;

class Node
{
public:
    int nodeId;
    vector<int> adjacentNodes;
    bool isVisited;
    Node(int id);
    Node();

    void add_adjacent(int adjacentNodeId);
};

#endif
