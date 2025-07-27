#include <iostream>
#include <vector>
using namespace std;

class Solution {
private:
    void dfs(int row, int col, int delrow[], int delcol[],
             vector<vector<int>>& ans, int iniColor, int newColor,
             vector<vector<int>>& image) {
        ans[row][col] = newColor;
        int n = image.size();
        int m = image[0].size();

        for (int i = 0; i < 4; i++) {
            int nrow = row + delrow[i];
            int ncol = col + delcol[i];

            if (nrow >= 0 && nrow < n && ncol >= 0 && ncol < m &&
                image[nrow][ncol] == iniColor && ans[nrow][ncol] != newColor) {
                dfs(nrow, ncol, delrow, delcol, ans, iniColor, newColor, image);
            }
        }
    }

public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc,
                                  int newColor) {
        int iniColor = image[sr][sc];
        vector<vector<int>> ans = image;
        int delrow[] = {-1, 0, +1, 0};
        int delcol[] = {0, +1, 0, -1};

        dfs(sr, sc, delrow, delcol, ans, iniColor, newColor, image);
        return ans;
    }
};

int main() {
    // Sample input
    vector<vector<int>> image = {
        {1, 1, 1},
        {1, 1, 0},
        {1, 0, 1}
    };
    int sr = 1, sc = 1, newColor = 2;

    Solution sol;
    vector<vector<int>> result = sol.floodFill(image, sr, sc, newColor);

    // Output the modified image
    cout << "Flood-filled image:\n";
    for (const auto& row : result) {
        for (int pixel : row) {
            cout << pixel << " ";
        }
        cout << "\n";
    }

    return 0;
}
