#include <iostream>
#include <vector>
#include "libs/file_operations/read_nodes.h"
#include "libs/bfs/bfs.h"
#include "libs/dfs/dfs.h"

using namespace std;

int main()
{
    // read from file and create node vector with adjacency's
    vector<Node> nodes = read_file("../matrix.txt");

    //* write adjacency's
    cout << "Node Id: Adjacent Node Id's" << endl;
    for (int i = 0; i < nodes.size(); i++)
    {
        cout << nodes[i].node_id << " : ";
        for (int j = 0; j < nodes[i].adjacent_nodes.size(); j++)
        {
            cout << nodes[i].adjacent_nodes[j].node_id << " ";
        }
        cout << endl;
    }

    BFS bfs(nodes);
    DFS dfs(nodes);

    bfs.print_order();
    dfs.print_order();

    return 0;
}