#include <iostream>
#include <vector>
using namespace std;
class Solution
{
private:
    int f(int day, int last, vector<vector<int>> &points, vector<vector<int>> &dp)
    {
        if (day == 0)
        {
            int maxi = 0;
            for (int task = 0; task < 3; task++)
            {
                if (task != last)
                {
                    maxi = max(maxi, points[0][task]);
                }
            }
            return maxi;
        }
        if (dp[day][last] != -1)
        {
            return dp[day][last];
        }
        int maxi = 0;
        for (int task = 0; task < 3; task++)
        {
            if (task != last)
            {
                int point = points[day][task] + f(day - 1, task, points, dp);
                maxi = max(maxi, point);
            }
        }
        return dp[day][last] = maxi;
    }

public:
    int ninjatraining(int n, vector<vector<int>> &points)
    {
        vector<vector<int>> dp(n, vector<int>(4, -1));
        return f(n - 1, 3, points, dp);
    }
};
int main()
{
    Solution sol;

    // Example input: 3 days, 3 tasks per day
    vector<vector<int>> points = {
        {10, 40, 70},
        {20, 50, 80},
        {30, 60, 90}};

    int n = points.size();

    cout << "Maximum points Ninja can earn: " << sol.ninjatraining(n, points) << endl;

    return 0;
}