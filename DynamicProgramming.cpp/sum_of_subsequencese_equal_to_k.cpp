#include <iostream>
#include <vector>
using namespace std;

class Solution
{
private:
    bool f(int ind, int target, vector<int> &arr, vector<vector<int>> &dp)
    {
        if (target == 0) return true;              // found subset
        if (ind == 0) return arr[0] == target;     // only first element left
        
        if (dp[ind][target] != -1)
            return dp[ind][target];

        bool nottake = f(ind - 1, target, arr, dp);
        bool take = false;
        if (arr[ind] <= target)
            take = f(ind - 1, target - arr[ind], arr, dp);

        return dp[ind][target] = take | nottake;
    }

public:
    bool subsetnumtok(int n, int k, vector<int> &arr)
    {
        vector<vector<int>> dp(n, vector<int>(k + 1, -1));
        return f(n - 1, k, arr, dp);
    }
};

int main()
{
    vector<int> arr = {1, 2, 3, 4, 5, 1};
    int k = 4;
    int n = arr.size();

    Solution sol;
    bool ans = sol.subsetnumtok(n, k, arr);

    cout << "The sum " << k << " exists in a subset or not? : " 
         << (ans ? "true" : "false") << endl;

    return 0;
}
