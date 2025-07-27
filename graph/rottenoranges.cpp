#include <bits/stdc++.h>
#include <iostream>
using namespace std;

class Solution {
  public:
    int orangesRotting(vector<vector<int>>& mat) {
        int n = mat.size();
        int m = mat[0].size();

        queue<pair<pair<int, int>, int>> q;
        vector<vector<int>> vis(n, vector<int>(m, 0));
        int cntFresh = 0;

        // Step 1: Enqueue all initially rotten oranges
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (mat[i][j] == 2) {
                    q.push({{i, j}, 0});
                    vis[i][j] = 2;
                } else {
                    vis[i][j] = 0;
                }
                if (mat[i][j] == 1) cntFresh++;
            }
        }

        int time = 0;
        int drow[] = {-1, 0, 1, 0};
        int dcol[] = {0, 1, 0, -1};
        int cnt = 0;

        // Step 2: BFS to rot adjacent oranges
        while (!q.empty()) {
            int r = q.front().first.first;
            int c = q.front().first.second;
            int t = q.front().second;
            q.pop();
            time = max(time, t);

            for (int i = 0; i < 4; i++) {
                int nrow = r + drow[i];
                int ncol = c + dcol[i];

                // rot only fresh oranges
                if (nrow >= 0 && nrow < n && ncol >= 0 && ncol < m
                    && vis[nrow][ncol] == 0 && mat[nrow][ncol] == 1) {
                    q.push({{nrow, ncol}, t + 1});
                    vis[nrow][ncol] = 2;
                    cnt++;
                }
            }
        }

        if (cnt != cntFresh) return -1;
        return time;
    }
};

// Example usage
int main() {
    vector<vector<int>> grid = {
        {2, 1, 1},
        {1, 1, 0},
        {0, 1, 1}
    };

    Solution sol;
    cout << sol.orangesRotting(grid) << endl; // Output should be 4

    return 0;
}
