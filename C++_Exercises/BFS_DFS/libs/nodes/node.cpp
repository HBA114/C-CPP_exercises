#include "node.h"

Node::Node(int id)
{
    nodeId = id;
    isVisited = false;
}

Node::Node()
{
}

void Node::add_adjacent(int adjacentNodeId)
{
    adjacentNodes.push_back(adjacentNodeId);
}
