#include <iostream>
#include <vector>
using namespace std;
class Solution
{
private:
    int f(int i, int j, vector<vector<int>> &triangle, vector<vector<int>> dp, int n)
    {
        if (i == n - 1)
        {
            return triangle[n - 1][j];
        }
        if (dp[i][j] != -1)
            return dp[i][j];
        int d = triangle[i][j] + f(i + 1, j, triangle, dp, n);
        int dg = triangle[i][j] + f(i + 1, j + 1, triangle, dp, n);
        return dp[i][j] = min(d, dg);
    }

public:
    int minimumPathSum(vector<vector<int>> triangle, int n)
    {
        vector<vector<int>> dp(n, vector<int>(n, -1));
        return f(0, 0, triangle, dp, n);
    }
};
int main()
{
    // Example triangle
    vector<vector<int>> triangle = {
        {2},
        {3, 4},
        {6, 5, 7},
        {4, 1, 8, 3}};

    int n = triangle.size();
    Solution sol;
    int ans = sol.minimumPathSum(triangle, n);

    cout << "Minimum path sum is: " << ans << endl;

    return 0;
}
