#include "libs/file_operations/read_nodes.h"
#include "libs/bfs/bfs.h"
#include "libs/dfs/dfs.h"

int main()
{
    // Read from file and create node vector with adjacency's
    vector<Node> nodes = read_file("../matrix.txt");
    vector<Node> nodes2 = read_file("../matrix2.txt");

    BFS bfs(nodes);
    DFS dfs(nodes);

    BFS bfs2(nodes2);
    DFS dfs2(nodes2);

    cout << "Output from matrix1.txt" << endl;

    cout << "Node Id: Adjacent Node Id's" << endl;
    for (int i = 0; i < nodes.size(); i++)
    {
        cout << nodes[i].nodeId << " : ";

        for (int j = 0; j < nodes[i].adjacentNodes.size(); j++)
            cout << nodes[i].adjacentNodes[j] << " ";

        cout << endl;
    }
    cout << endl;

    bfs.print_order();
    dfs.print_order();

    cout << endl;
    cout << "Output from matrix2.txt" << endl;

    cout << "Node Id: Adjacent Node Id's" << endl;
    for (int i = 0; i < nodes2.size(); i++)
    {
        cout << nodes2[i].nodeId << " : ";

        for (int j = 0; j < nodes2[i].adjacentNodes.size(); j++)
            cout << nodes2[i].adjacentNodes[j] << " ";

        cout << endl;
    }
    cout << endl;

    bfs2.print_order();
    dfs2.print_order();
    return 0;
}
