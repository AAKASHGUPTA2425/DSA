#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    bool dfs(int node, vector<vector<int>> &adj, vector<int> &vis, vector<int> &pathvis) {
        vis[node] = 1;
        pathvis[node] = 1;

        for (auto t : adj[node]) {
            if (!vis[t]) {
                if (dfs(t, adj, vis, pathvis)) 
                    return true;
            } 
            else if (pathvis[t]) {
                return true;  // cycle found
            }
        }

        pathvis[node] = 0; // backtrack
        return false;
    }

public:
    bool isCyclic(int V, vector<vector<int>> &edges) {
        // build adjacency list
        vector<vector<int>> adj(V);
        for (auto &e : edges) {
            int u = e[0];
            int v = e[1];
            adj[u].push_back(v);   // directed edge
        }

        vector<int> vis(V, 0), pathvis(V, 0);

        for (int i = 0; i < V; i++) {
            if (!vis[i]) {
                if (dfs(i, adj, vis, pathvis)) 
                    return true;
            }
        }
        return false;
    }
};

int main() {
    int V, E;
    cout << "Enter number of vertices and edges: ";
    cin >> V >> E;

    vector<vector<int>> edges(E, vector<int>(2));
    cout << "Enter edges (u v) for directed graph:\n";
    for (int i = 0; i < E; i++) {
        cin >> edges[i][0] >> edges[i][1];
    }

    Solution sol;
    if (sol.isCyclic(V, edges)) {
        cout << "Graph contains a cycle\n";
    } else {
        cout << "Graph does NOT contain a cycle\n";
    }

    return 0;
}
