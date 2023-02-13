#ifndef NODE_H
#define NODE_H
#include <iostream>
#include <vector>

using namespace std;

class Node
{
public:
    int node_id;
    vector<int> adjacent_nodes;
    bool is_visited;
    Node(int id);
    Node();

    void add_adjacent(int adjacent_node_id);
};

#endif