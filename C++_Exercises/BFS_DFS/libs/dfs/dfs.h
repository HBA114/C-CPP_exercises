#ifndef DFS_H
#define DFS_H

#include "../nodes/node.h"

class DFS
{
private:
    vector<Node> nodes;

public:
    DFS(vector<Node> nodes);
    void print_order();
};

#endif
