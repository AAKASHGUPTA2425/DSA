#include <iostream>
#include <vector>
using namespace std;
class solution
{
public:
    int kadane(vector<int> &nums)
    {
        int countSum = nums[0];
        int maxSum = nums[0];
        for (int i = 1; i < nums.size(); i++)
        {
            countSum = max(nums[i], countSum + nums[i]);
            maxSum = max(countSum, maxSum);
        }
        return maxSum;
    }
};
int main()
{
    cout<<"program executed..."<<endl;
    vector<int> nums = {-2, 1, -3, 4, -1, 2, 1, -5, 4};
    solution sol;
    int Max_sum = sol.kadane(nums);
    if (Max_sum)
    {
        cout << Max_sum << endl;
    }
    return 0;
}