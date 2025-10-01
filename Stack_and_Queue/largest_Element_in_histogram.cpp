#include <iostream>
#include <stack>
#include <vector>
using namespace std;

class Solution
{
public:
    int function(vector<int> &arr, int n)
    {
        stack<int> st;
        int maxArea = 0;

        for (int i = 0; i < n; i++)
        {
            while (!st.empty() && arr[st.top()] > arr[i])
            {
                int element = st.top();
                st.pop();
                int nse = i;
                int pse = st.empty() ? -1 : st.top();
                maxArea = max((arr[element] * (nse - pse - 1)), maxArea);
            }
            st.push(i);
        }

        // process remaining elements in stack
        while (!st.empty())
        {
            int element = st.top();
            st.pop();
            int nse = n;
            int pse = st.empty() ? -1 : st.top();
            maxArea = max((arr[element] * (nse - pse - 1)), maxArea);
        }

        return maxArea;
    }
};
int main()
{
    Solution sol;

    // Example histogram
    vector<int> arr = {2, 1, 5, 6, 2, 3};
    int n = arr.size();

    cout << "Largest Rectangle Area = " << sol.function(arr, n) << endl;

    return 0;
}
