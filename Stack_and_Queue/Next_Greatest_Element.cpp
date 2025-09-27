#include <iostream>
#include <stack>
#include <vector>
using namespace std;

class Solution
{
public:
    vector<int> findNGE(vector<int> &arr, int n)
    {
        vector<int> nge(n, -1);
        stack<int> st;
        for (int i = n - 1; i >= 0; i--)
        {
            while (!st.empty() && st.top() <= arr[i])
                st.pop();
            if (st.empty())
                nge[i] = -1;
            else
                nge[i] = st.top();
            st.push(arr[i]);
        }
        return nge;
    }
};

int main()
{
    Solution sol;
    vector<int> arr = {4, 5, 2, 25, 7, 8};
    int n = arr.size();

    vector<int> result = sol.findNGE(arr, n);

    cout << "Next Greater Elements:\n";
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " -> " << result[i] << endl;
    }

    return 0;
}
