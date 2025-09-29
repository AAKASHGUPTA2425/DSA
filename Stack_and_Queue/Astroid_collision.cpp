#include <iostream>
#include <vector>
#include <stack>
using namespace std;

class Solution
{
public:
    vector<int> Astroid_collision(vector<int> &arr, int n)
    {
        vector<int> st;
        for (int i = 0; i < n; i++) // ✅ should go till n not n-1
        {
            if (arr[i] > 0)
                st.push_back(arr[i]);
            else
            {
                while (!st.empty() && st.back() > 0 && st.back() < abs(arr[i]))
                {
                    st.pop_back();
                }
                if (!st.empty() && st.back() == abs(arr[i]))
                {
                    st.pop_back();
                }
                else if (st.empty() || st.back() < 0)
                    st.push_back(arr[i]);
            }
        }
        return st;
    }
};

int main()
{
    Solution sol;
    vector<int> arr = {5, 10, -5}; // sample input
    int n = arr.size();

    vector<int> result = sol.Astroid_collision(arr, n);

    cout << "Result after asteroid collision: ";
    for (int x : result)
    {
        cout << x << " ";
    }
    cout << endl;

    return 0;
}
