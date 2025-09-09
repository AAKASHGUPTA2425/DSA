#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Graph {
private:
    vector<vector<int>> adjList;
    bool directed;
    int numVertices;

public:
    // Constructor
    Graph(int vertices, bool isDirected = false) {
        numVertices = vertices;
        directed = isDirected;
        adjList.resize(vertices);  // allocate space
    }

    // Add edge
    void addEdge(int u, int v) {
        adjList[u].push_back(v);
        if (!directed) {
            adjList[v].push_back(u);
        }
    }

    // Display graph
    void display() {
        for (int i = 0; i < numVertices; i++) {
            cout << i << " = ";
            for (int neighbor : adjList[i]) {
                cout << neighbor << " ";
            }
            cout << endl;
        }
    }

    // Accessor
    vector<vector<int>> getAdjList() {
        return adjList;
    }
};
bool DetectCycle(int node, int parent, vector<bool> &visited, const vector<vector<int>> &adjList) {
    visited[node] = true;

    for (int neighbor : adjList[node]) {
        if (!visited[neighbor]) {
            if (DetectCycle(neighbor, node, visited, adjList)) {
                return true;
            }
        } else if (neighbor != parent) {
            // Visited and not parent → back edge → cycle
            return true;
        }
    }
    return false;
}
bool cycleDetected(int V, const vector<vector<int>> &adjList) {
    vector<bool> visited(V, false);
    //this loop is for any type of graph either there is connected node or not connected node exist
    for (int i = 0; i < V; i++) {
        if (!visited[i]) {
            if (DetectCycle(i, -1, visited, adjList)) {
                return true;
            }
        }
    }
    return false;
}
int main() {
    int V = 6;
    Graph g(V, false);  // undirected graph

    g.addEdge(0, 1);
    g.addEdge(1, 2);
    g.addEdge(2, 3);
    g.addEdge(3, 4);
    g.addEdge(4, 1);  // introduces a cycle

    g.display();

    if (cycleDetected(V, g.getAdjList())) {
        cout << "Cycle detected in the graph." << endl;
    } else {
        cout << "No cycle detected." << endl;
    }

    return 0;
}
