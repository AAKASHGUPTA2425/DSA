#include <iostream>
#include <vector>
#include <deque>
using namespace std;
vector<int> sliding_window_maximum(vector<int> nums, int k)
{
    deque<int> dq;      // deque having the index in it only
    vector<int> result; // result having the maximum value among k limit
    for (int i = 0; i < nums.size(); i++)
    {

        if (!dq.empty() && dq.front() == i - k)
        {
            dq.pop_front();
        }

        while (!dq.empty() && nums[dq.back()] < nums[i])
            dq.pop_back();

        dq.push_back(i);

        if (i >= k - 1)
        {
            result.push_back(nums[dq.front()]);
        }
    }
    return result;
}

int main()
{
    vector<int> v = {1,3,-1,-3,5,3,6,7};
    int k = 3;
    vector<int> result = sliding_window_maximum(v, k);
    for (int i = 0; i < result.size(); i++)
    {
        cout << result[i] << " ";
    }
    cout << endl;
    return 0;
}