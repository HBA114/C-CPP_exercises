#include "dfs.h"

DFS::DFS(vector<Node> nodes)
{
    this->nodes = nodes;
}

void DFS::print_order()
{
    vector<Node> queue;
    vector<Node> visit_order;

    // Visit Order should be: 0 -> 1 -> 2 -> 3 -> 4 . for matrix.txt
    // Visit Order should be: 0 -> 1 -> 3 -> 5 -> 2 -> 6 -> 4 . for matrix2.txt

    queue.push_back(nodes[0]);
    int queue_index = 0;

    while (queue.size() > 0)
    {
        int count = 1;
        for (int i = 0; i < queue[queue_index].adjacentNodes.size(); i++)
        {
            bool control = true;
            for (int j = 0; j < queue.size(); j++)
            {
                if (queue[j].nodeId == queue[queue_index].adjacentNodes[i])
                {
                    control = false;
                    break;
                }
            }

            if (control && nodes[queue[queue_index].adjacentNodes[i]].isVisited == false)
            {
                queue.insert(queue.begin() + queue_index + count, nodes[queue[queue_index].adjacentNodes[i]]);
                count++;
            }
        }

        queue[queue_index].isVisited = true;
        nodes[queue[queue_index].nodeId].isVisited = true;
        visit_order.push_back(queue[queue_index]);
        queue.erase(queue.begin());

        cout << "";
    }

    cout << "Depth First Search Visit Order:" << endl;
    for (int i = 0; i < visit_order.size(); i++)
    {
        cout << visit_order[i].nodeId;
        i != visit_order.size() - 1 ? cout << " -> " : cout << "";
    }
    cout << endl;
}
