#include "node.h"

Node::Node(int id)
{
    node_id = id;
    is_visited = false;
}

Node::Node()
{
}

void Node::add_adjacent(int adjacent_node_id)
{
    adjacent_nodes.push_back(adjacent_node_id);
}
