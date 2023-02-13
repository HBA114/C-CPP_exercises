#include "bfs.h"

BFS::BFS(vector<Node> nodes)
{
    this->nodes = nodes;
}

void BFS::print_order()
{
    cout << "BFS Search Order:" << endl;
    vector<Node> queue;
    vector<Node> visit_order;

    queue.push_back(nodes[0]);

    while (queue.size() > 0)
    {
        for (int i = 0; i < queue[0].adjacent_nodes.size(); i++)
        {
            bool control = true;
            for (int j = 0; j < queue.size(); j++)
            {
                if (queue[j].node_id == queue[0].adjacent_nodes[i])
                {
                    control = false;
                    break;
                }
            }

            if (control && nodes[queue[0].adjacent_nodes[i]].is_visited == false)
            {
                queue.push_back(nodes[queue[0].adjacent_nodes[i]]);
            }
        }

        queue[0].is_visited = true;
        nodes[queue[0].node_id].is_visited = true;
        visit_order.push_back(queue[0]);
        queue.erase(queue.begin());
    }

    cout << "BFS Visit Order:" << endl;
    for (int i = 0; i < visit_order.size(); i++)
    {
        cout << visit_order[i].node_id;
        i != visit_order.size() - 1 ? cout << " -> " : cout << "";
    }
    cout << endl;
}
