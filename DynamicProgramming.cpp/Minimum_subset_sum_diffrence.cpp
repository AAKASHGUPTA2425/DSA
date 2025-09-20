#include <iostream>
#include <vector>
#include <climits>
using namespace std;

class Solution
{
public:
    int MinimumSubsetSumDiffrence(vector<int> &arr, int n)
    {
        int totalSum = 0;
        for (int i = 0; i < n; i++)
            totalSum += arr[i];
        int k = totalSum;

        vector<vector<bool>> dp(n, vector<bool>(k + 1, false));

        // Base cases
        for (int i = 0; i < n; i++)
            dp[i][0] = true;
        if (arr[0] <= k)
            dp[0][arr[0]] = true;

        for (int ind = 1; ind < n; ind++)
        {
            for (int target = 1; target <= k; target++)
            {
                bool NotTake = dp[ind - 1][target];
                bool Take = false;
                if (arr[ind] <= target)
                    Take = dp[ind - 1][target - arr[ind]];
                dp[ind][target] = Take | NotTake;
            }
        }

        int mini = INT_MAX;
        for (int s1 = 0; s1 <= totalSum / 2; s1++)
        {
            if (dp[n - 1][s1] == true)
            {
                mini = min(mini, abs((totalSum - s1) - s1));
            }
        }
        return mini;
    }
};

int main()
{
    Solution sol;

    vector<int> arr = {1, 2, 7};
    int n = arr.size();

    cout << "Minimum Subset Sum Difference = "
         << sol.MinimumSubsetSumDiffrence(arr, n) << endl;

    return 0;
}
