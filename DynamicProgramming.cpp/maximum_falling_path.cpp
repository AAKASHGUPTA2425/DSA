#include <iostream>
#include <vector>
#include <climits>
using namespace std;

class Solution
{
private:
    int f(int i, int j, vector<vector<int>> &matrix, vector<vector<int>> &dp)
    {
        if (j < 0 || j >= matrix[0].size())
            return INT_MIN;  // invalid move → very small value
        if (i == 0)
            return matrix[0][j];
        if (dp[i][j] != -1)
            return dp[i][j];

        int s = matrix[i][j] + f(i - 1, j, matrix, dp);
        int ld = matrix[i][j] + f(i - 1, j - 1, matrix, dp);
        int rd = matrix[i][j] + f(i - 1, j + 1, matrix, dp);

        return dp[i][j] = max(s, max(ld, rd));
    }

public:
    int getmaxPath(vector<vector<int>> &matrix)
    {
        int n = matrix.size();
        int m = matrix[0].size();
        vector<vector<int>> dp(n, vector<int>(m, -1));
        int maxi = INT_MIN;

        for (int j = 0; j < m; j++)
        {
            maxi = max(maxi, f(n - 1, j, matrix, dp));
        }
        return maxi;
    }
};

int main()
{
    int n = 4, m = 4;
    vector<vector<int>> matrix(n, vector<int>(m));

    cout << "Enter a 4x4 matrix:\n";
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cout << "Enter element [" << i << "][" << j << "]: ";
            cin >> matrix[i][j];
        }
    }

    Solution sol;
    int ans = sol.getmaxPath(matrix);
    cout << "Maximum falling path: " << ans << endl;

    return 0;
}
