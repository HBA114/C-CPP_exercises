#ifndef BFS_H
#define BFS_H

#include <iostream>
#include <vector>
#include "../nodes/node.h"

class BFS
{
private:
    vector<Node> nodes;
public:
    BFS(vector<Node> nodes);
    void print_order();
};

#endif