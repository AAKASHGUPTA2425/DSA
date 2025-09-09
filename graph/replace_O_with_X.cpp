#include <iostream>
#include <vector>
using namespace std;

class Solution {
private:
    void dfs(int row, int col, vector<vector<int>>& vis, vector<vector<char>>& mat, int delrow[], int delcol[]) {
        vis[row][col] = 1;
        int n = mat.size();
        int m = mat[0].size();

        for(int i = 0; i < 4; i++) {
            int nrow = row + delrow[i];
            int ncol = col + delcol[i];

            if(nrow >= 0 && nrow < n && ncol >= 0 && ncol < m 
               && !vis[nrow][ncol] && mat[nrow][ncol] == 'O') {
                dfs(nrow, ncol, vis, mat, delrow, delcol);
            }
        }
    }

public:
    vector<vector<char>> fill(vector<vector<char>>& mat) {
        int n = mat.size();
        int m = mat[0].size();
        vector<vector<int>> vis(n, vector<int>(m, 0));

        int delrow[] = {-1, 0, 1, 0};
        int delcol[] = {0, 1, 0, -1};

        // DFS from first and last row
        for(int j = 0; j < m; j++) {
            if(!vis[0][j] && mat[0][j] == 'O') dfs(0, j, vis, mat, delrow, delcol);
            if(!vis[n-1][j] && mat[n-1][j] == 'O') dfs(n-1, j, vis, mat, delrow, delcol);
        }

        // DFS from first and last column
        for(int i = 0; i < n; i++) {
            if(!vis[i][0] && mat[i][0] == 'O') dfs(i, 0, vis, mat, delrow, delcol);
            if(!vis[i][m-1] && mat[i][m-1] == 'O') dfs(i, m-1, vis, mat, delrow, delcol);
        }

        // Replace all unvisited 'O' with 'X'
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(!vis[i][j] && mat[i][j] == 'O') mat[i][j] = 'X';
            }
        }

        return mat;
    }
};

int main() {
    int n, m;
    cout << "Enter number of rows and columns: ";
    cin >> n >> m;

    vector<vector<char>> mat(n, vector<char>(m));
    cout << "Enter the matrix (O and X only):\n";
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            cin >> mat[i][j];
        }
    }

    Solution sol;
    vector<vector<char>> result = sol.fill(mat);

    cout << "Updated matrix:\n";
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            cout << result[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}
