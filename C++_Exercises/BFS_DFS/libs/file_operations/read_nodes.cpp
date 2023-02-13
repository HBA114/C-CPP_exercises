#include "read_nodes.h"

vector<Node> read_file(string file_name)
{
    ifstream Matrix(file_name);

    string line;
    vector<string> lines;

    if (!Matrix.is_open())
        cout << "File not found!" << endl;

    while (getline(Matrix, line))
        lines.push_back(line);

    vector<Node> nodes;
    for (int i = 0; i < lines.size(); i++)
    {
        Node node(i);
        nodes.push_back(node);
    }

    for (int i = 0; i < lines.size(); i++)
    {
        int j_index = 0;

        for (int j = 0; j < lines[i].length(); j += 2)
        {
            if (lines[i][j] == '1')
            {
                bool control = true;
                for (int k = 0; k < nodes[i].adjacent_nodes.size(); k++)
                {
                    if (nodes[i].adjacent_nodes[k] == nodes[j_index].node_id)
                    {
                        control = false;
                        break;
                    }
                }

                if (control)
                    nodes[i].add_adjacent(j_index);
            }
            j_index++;
        }

        // for (int j = 0; j < lines[i].length(); j += 2)
        // {
        //     if (lines[i][j] == '1')
        //     {
        //         bool control = true;
        //         for (int k = 0; k < nodes[i].adjacent_nodes.size(); k++)
        //         {
        //             if (nodes[i].adjacent_nodes[k].node_id == nodes[j_index].node_id)
        //             {
        //                 control = false;
        //                 break;
        //             }
        //         }

        //         if (control)
        //             nodes[i].add_adjacent(nodes[j_index]);
        //     }
        //     j_index++;
        // }
    }

    Matrix.close();
    return nodes;
}
