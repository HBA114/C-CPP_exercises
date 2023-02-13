#ifndef NODE_H
#define NODE_H
#include <iostream>
#include <vector>

using namespace std;

class Node
{
public:
    int node_id;
    vector<Node> adjacent_nodes;
    bool is_visited;
    Node(int id);

    void add_adjacent(Node adjacent_node);
};

#endif