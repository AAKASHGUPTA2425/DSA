#include <iostream>
#include <vector>
using namespace std;
class Solution
{
private:
    bool f(int ind, int target, vector<int> &arr, vector<vector<int>> &dp)
    {
        if (target == 0)
            return true;
        if (dp[ind][target] != -1)
            return dp[ind][target];
        bool nottake = f(ind - 1, target, arr, dp);
        bool take = false;
        if (arr[ind] <= target)
            take = f(ind - 1, target - arr[ind], arr, dp);
        return dp[ind][target] = take | nottake;
    }
    bool subsetnumtok(int n, int k, vector<int> &arr)
    {
        vector<vector<int>> dp(n, vector<int>(k + 1, -1));
        return f(n - 1, k, arr, dp);
    }

public:
    bool canPartition(int n, vector<int> &arr)
    {
        int totalSum = 0;
        for (int i = 0; i < n; i++)
            totalSum += arr[i];
        if (totalSum % 2)
            return false;
        int target = totalSum / 2;
        return subsetnumtok(n, target, arr);
    }
};

int main()
{
    Solution sol;

    vector<int> arr = {1, 5, 11, 5};
    int n = arr.size();

    if (sol.canPartition(n, arr))
        cout << "The array can be partitioned into two subsets with equal sum." << endl;
    else
        cout << "The array cannot be partitioned into two subsets with equal sum." << endl;

    return 0;
}
