#include <iostream>
#include <map>
#include <list>
#include <vector>
#include <queue>
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
vector<int> bfs(map<int, list<int>> adjList)
{
    int v = adjList.size();
    queue<int> q;
    vector<bool> visited(v, 0);
    vector<int> ans;
    q.push(0);
    visited[0] = 1;
    while (!q.empty())
    {
        int node = q.front();
        q.pop();
        ans.push_back(node);
        for (int j : adjList[node])
        {
            if (!visited[j])
            {
                visited[j] = 1;
                q.push(j);
            }
        }
    }
    return ans;
}
int main()
{
    Graph g(false); // false means undirected graph

    // Add some edges
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 3);
    g.addEdge(2, 4);
    g.addEdge(3, 5);
    g.addEdge(4, 5);

    cout << "Adjacency List of Graph:\n";
    g.display();

    // Perform BFS from node 0
    cout << "\nBFS Traversal starting from node 0:\n";
    vector<int> traversal = bfs(g.getAdjList()); // ERROR: adjList is private

    for (int node : traversal)
    {
        cout << node << " ";
    }
    cout << endl;

    return 0;
}
