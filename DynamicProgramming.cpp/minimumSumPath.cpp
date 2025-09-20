#include <iostream>
#include <vector>
#include <climits>
using namespace std;

class Solution
{
private:
    int f(int n, int m, vector<vector<int>> &dp, vector<vector<int>> &a)
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (i == 0 && j == 0)
                    dp[i][j] = a[0][0];
                else
                {
                    int up = INT_MAX, left = INT_MAX;
                    if (i > 0)
                        up = a[i][j] + dp[i - 1][j];
                    if (j > 0)
                        left = a[i][j] + dp[i][j - 1];
                    dp[i][j] = min(up, left);
                }
            }
        }
        return dp[n - 1][m - 1];
    }

public:
    int minimumsumpath(vector<vector<int>> a)
    {
        int n = a.size();
        int m = a[0].size();
        vector<vector<int>> dp(n, vector<int>(m, 0));
        return f(n, m, dp, a);
    }
};

int main()
{
    Solution sol;

    vector<vector<int>> grid = {
        {1, 3, 1},
        {1, 5, 1},
        {4, 2, 1}};

    cout << "Minimum Path Sum = " << sol.minimumsumpath(grid) << endl;

    return 0;
}
