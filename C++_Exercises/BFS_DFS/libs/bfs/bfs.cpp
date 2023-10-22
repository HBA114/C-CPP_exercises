#include "bfs.h"

BFS::BFS(vector<Node> nodes)
{
    this->nodes = nodes;
}

void BFS::print_order()
{
    vector<Node> queue;
    vector<Node> visit_order;

    // Visit Order should be: 0 -> 1 -> 3 -> 4 -> 2 . for matrix.txt
    // Visit Order should be: 0 -> 1 -> 2 -> 4 -> 3 -> 5 -> 6 . for matrix2.txt

    queue.push_back(nodes[0]);

    while (queue.size() > 0)
    {
        for (int i = 0; i < queue[0].adjacentNodes.size(); i++)
        {
            bool control = true;
            for (int j = 0; j < queue.size(); j++)
            {
                if (queue[j].nodeId == queue[0].adjacentNodes[i])
                {
                    control = false;
                    break;
                }
            }

            if (control && nodes[queue[0].adjacentNodes[i]].isVisited == false)
                queue.push_back(nodes[queue[0].adjacentNodes[i]]);
        }

        queue[0].isVisited = true;
        nodes[queue[0].nodeId].isVisited = true;
        visit_order.push_back(queue[0]);
        queue.erase(queue.begin());
    }

    cout << "Breadth First Search Visit Order:" << endl;
    for (int i = 0; i < visit_order.size(); i++)
    {
        cout << visit_order[i].nodeId;
        i != visit_order.size() - 1 ? cout << " -> " : cout << "";
    }
    cout << endl;
}
