#include <iostream>
#include <map>
#include <list>
#include <vector>
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
    map<int, list<int>> getAdjList()
    {
        return adjList;
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
void dfs(int node, map<int, list<int>> &adjList, vector<bool> &visited, vector<int> &ans)
{
    visited[node] = 1;
    ans.push_back(node);
    for (int j : adjList[node])
    {
        if (!visited[j])
        {
            dfs(j, adjList, visited, ans);
        }
    }
}
int main()
{
    Graph g(false); // false means undirected graph

    // Add edges to the graph
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 3);
    g.addEdge(2, 4);
    g.addEdge(3, 5);
    g.addEdge(4, 5);

    // Display the graph
    cout << "Adjacency List of Graph:\n";
    g.display();

    // Perform DFS starting from node 0
    map<int, list<int>> adj = g.getAdjList();
    int startNode = 0;
    int size = adj.size();

    // Get the maximum node value to size visited array safely
    int maxNode = 0;
    for (auto &p : adj)
    {
        maxNode = max(maxNode, p.first);
        for (int neighbor : p.second)
            maxNode = max(maxNode, neighbor);
    }

    vector<bool> visited(maxNode + 1, false);
    vector<int> dfsResult;

    cout << "\nDFS Traversal starting from node " << startNode << ":\n";
    dfs(startNode, adj, visited, dfsResult);

    for (int node : dfsResult)
    {
        cout << node << " ";
    }
    cout << endl;

    return 0;
}
