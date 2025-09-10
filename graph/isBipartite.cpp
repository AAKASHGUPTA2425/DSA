#include <iostream>
#include <vector>
#include <queue>
using namespace std;

// Your Solution class goes here
class Solution {
public:
    bool isBipartite(int V, vector<vector<int>> &edges) {
        // Convert edge list to adjacency list
        vector<vector<int>> adj(V);
        for(auto &e : edges){
            int u = e[0];
            int v = e[1];
            adj[u].push_back(v);
            adj[v].push_back(u); // undirected graph
        }

        vector<int> color(V, -1);

        for(int i = 0; i < V; i++){
            if(color[i] == -1){
                queue<int> q;
                q.push(i);
                color[i] = 0;

                while(!q.empty()){
                    int node = q.front();
                    q.pop();

                    for(auto t: adj[node]){
                        if(color[t] == -1){
                            color[t] = !color[node];
                            q.push(t);
                        }
                        else if(color[t] == color[node]){
                            return false;
                        }
                    }
                }
            }
        }

        return true;
    }
};

int main() {
    int V, E;
    cout << "Enter number of vertices: ";
    cin >> V;
    cout << "Enter number of edges: ";
    cin >> E;

    vector<vector<int>> edges(E, vector<int>(2));
    cout << "Enter edges (u v) for each edge:\n";
    for(int i = 0; i < E; i++){
        cin >> edges[i][0] >> edges[i][1];
    }

    Solution sol;
    bool result = sol.isBipartite(V, edges);

    if(result)
        cout << "Graph is Bipartite\n";
    else
        cout << "Graph is NOT Bipartite\n";

    return 0;
}
