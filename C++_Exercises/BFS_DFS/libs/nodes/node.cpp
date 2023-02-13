#include "node.h"

Node::Node(int id)
{
    node_id = id;
    is_visited = false;
}

void Node::add_adjacent(Node adjacent_node)
{
    adjacent_nodes.push_back(adjacent_node);
}
