#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Graph
{
private:
    vector<vector<int>> adjList;
    bool directed;
    int numVertices;

public:
    // Constructor
    Graph(int vertices, bool isDirected = false)
    {
        numVertices = vertices;
        directed = isDirected;
        adjList.resize(vertices); // allocate space
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

    // Display graph
    void display()
    {
        for (int i = 0; i < numVertices; i++)
        {
            cout << i << " = ";
            for (int neighbor : adjList[i])
            {
                cout << neighbor << " ";
            }
            cout << endl;
        }
    }

    // Accessor
    vector<vector<int>> getAdjList()
    {
        return adjList;
    }
};
bool bfs(vector<vector<int>> adjList, vector<bool> &visited)
{
    queue<pair<int, int>> q;
    visited[0] = 1;
    q.push(make_pair(0, -1));
    while (!q.empty())
    {
        int node = q.front().first;
        int parent = q.front().second;
        q.pop();
        for (int j = 0; j < adjList[node].size(); j++)
        {
            if (parent == adjList[node][j])
                continue;
            if (visited[adjList[node][j]])
                return 1;

            visited[adjList[node][j]] = 1;
            q.push(make_pair(adjList[node][j], node));
        }
    }
    return 0;
}
bool cycleDetected(int V, vector<vector<int>> adjlist)
{
    vector<bool> visited(V, 0);
    return bfs(adjlist, visited);
}
int main() {
    int V = 6;  // number of vertices
    Graph g(V, false);  // false = undirected

    // Add edges
    g.addEdge(0, 1);
    g.addEdge(1, 2);
    g.addEdge(2, 3);
    g.addEdge(3, 4);
    g.addEdge(4, 1);  // Introduces a cycle

    // Display the adjacency list
    cout << "Adjacency List of Graph:\n";
    g.display();

    // Run cycle detection using BFS
    if (cycleDetected(V, g.getAdjList())) {
        cout << "\nCycle detected in the graph.\n";
    } else {
        cout << "\nNo cycle detected in the graph.\n";
    }

    return 0;
}
