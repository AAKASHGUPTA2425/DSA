#include <iostream>
#include <map>
#include <list>
using namespace std;

class Graph
{
private:
    map<int, list<int>> adjList;
    bool directed;

public:
    // Constructor
    Graph(bool isDirected = false)
    {
        directed = isDirected;
    }

    // Add vertex (optional in C++, since we add automatically in addEdge)
    void addVertex(int vertex)
    {
        if (adjList.find(vertex) == adjList.end())
        {
            adjList[vertex] = list<int>();
        }
    }

    // Add edge
    void addEdge(int u, int v)
    {
        adjList[u].push_back(v);
        if (!directed)
        {
            adjList[v].push_back(u);
        }
    }

    // Remove edge
    void removeEdge(int u, int v)
    {
        adjList[u].remove(v);
        if (!directed)
        {
            adjList[v].remove(u);
        }
    }

    // Remove vertex
    void removeVertex(int vertex)
    {
        // Remove this vertex from other adjacency lists
        for (auto &pair : adjList)
        {
            pair.second.remove(vertex);
        }

        // Remove the vertex itself
        adjList.erase(vertex);
    }

    // Display the graph
    void display()
    {
        for (auto &pair : adjList)
        {
            cout << pair.first << " = ";
            for (int neighbor : pair.second)
            {
                cout << neighbor << " ";
            }
            cout << endl;
        }
    }
};
int main()
{
    Graph g(false); // false = undirected graph

    g.addEdge(1, 2);
    g.addEdge(1, 3);
    g.addEdge(2, 4);
    g.addEdge(3, 4);
    g.addEdge(4, 5);

    cout << "Graph adjacency list:" << endl;
    g.display();

    g.removeEdge(3, 4);
    cout << "\nAfter removing edge (3, 4):" << endl;
    g.display();

    g.removeVertex(4);
    cout << "\nAfter removing vertex 4:" << endl;
    g.display();

    return 0;
}
