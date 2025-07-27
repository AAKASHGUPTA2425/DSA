#include <vector>
#include <iostream>
using namespace std;

void dfs(int row, int col, vector<vector<int>> &grid, int n, int m) {
    grid[row][col] = 0; // mark as visited (turn land back to water)
    int dr[] = {-1, 0, 1, 0};
    int dc[] = {0, 1, 0, -1};

    for (int i = 0; i < 4; i++) {
        int nr = row + dr[i];
        int nc = col + dc[i];

        if (nr >= 0 && nr < n && nc >= 0 && nc < m && grid[nr][nc] == 1) {
            dfs(nr, nc, grid, n, m);
        }
    }
}

int countIslands(vector<vector<int>> &grid, int n, int m) {
    int count = 0;
    vector<vector<int>> temp = grid; // copy grid so original isn't modified

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (temp[i][j] == 1) {
                count++;
                dfs(i, j, temp, n, m);
            }
        }
    }
    return count;
}

vector<int> numOfIslands(int n, int m, vector<vector<int>> &operators) {
    vector<vector<int>> grid(n, vector<int>(m, 0));
    vector<int> result;

    for (auto &op : operators) {
        int r = op[0], c = op[1];
        grid[r][c] = 1; // turn water into land
        int count = countIslands(grid, n, m); // count islands after this op
        result.push_back(count);
    }

    return result;
}
int main() {
    int n = 3, m = 3;
    vector<vector<int>> ops = {{0,0}, {0,1}, {1,2}, {2,1}, {1,1}};
    vector<int> res = numOfIslands(n, m, ops);

    for (int cnt : res) {
        cout << cnt << " ";
    }
    return 0;
}
