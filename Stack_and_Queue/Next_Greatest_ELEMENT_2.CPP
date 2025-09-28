#include <iostream>
#include <vector>
#include <stack>
using namespace std;

class Solution
{
public:
    vector<int> findNGE(vector<int> &arr, int n)
    {
        vector<int> nge(n, -1);
        stack<int> st;
        for (int i = 2 * n - 1; i >= 0; i--)
        {
            while (!st.empty() && st.top() <= arr[i % n])
            {
                st.pop();
            }
            if (i < n)
            {
                nge[i] = st.empty() ? -1 : st.top();
            }
            st.push(arr[i % n]);
        }
        return nge;
    }
};

int main()
{
    Solution sol;
    vector<int> arr = {5, 7, 1, 2, 6, 0}; // Example circular array
    int n = arr.size();

    vector<int> result = sol.findNGE(arr, n);

    cout << "Next Greater Elements (circular):\n";
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " -> " << result[i] << endl;
    }

    return 0;
}
