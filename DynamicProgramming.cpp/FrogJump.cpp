#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    int f(int n, vector<int>& heights, vector<int>& dp) {
        if (n == 0) return 0;
        if (dp[n] != -1) return dp[n];

        int left = f(n - 1, heights, dp) + abs(heights[n] - heights[n - 1]);

        int right = INT_MAX;
        if (n > 1)
            right = f(n - 2, heights, dp) + abs(heights[n] - heights[n - 2]);

        return dp[n] = min(left, right);
    }

public:
    int frogJump(vector<int>& heights) {
        int n = heights.size();
        vector<int> dp(n, -1);
        return f(n - 1, heights, dp);
    }
};

int main() {
    Solution sol;

    // Example input
    vector<int> heights = {30, 10, 60, 10, 50, 70};

    // Output the minimum cost
    cout << "Minimum energy required: " << sol.frogJump(heights) << endl;

    return 0;
}
