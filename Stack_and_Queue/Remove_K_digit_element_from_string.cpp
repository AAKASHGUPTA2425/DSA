#include <iostream>
#include <stack>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

class Solution
{
public:
    string function(string s, int K)
    {
        stack<char> st;
        int n = s.size();

        // Step 1: Process digits with monotonic stack
        for (int i = 0; i < n; i++)
        {
            while (!st.empty() && K > 0 && (st.top() - '0') > (s[i] - '0'))
            {
                st.pop();
                K--;
            }
            st.push(s[i]);
        }

        // Step 2: Remove extra digits if K still > 0
        while (K > 0 && !st.empty())
        {
            st.pop();
            K--;
        }

        // Step 3: Build result from stack
        string result = "";
        while (!st.empty())
        {
            result.push_back(st.top());
            st.pop();
        }

        // reverse because we built it backwards
        reverse(result.begin(), result.end());

        // Step 4: Remove leading zeros
        int idx = 0;
        while (idx < (int)result.size() && result[idx] == '0')
            idx++;

        result = result.substr(idx);

        if (result.empty())
            return "0";

        return result;
    }
};
int main()
{
    Solution sol;
    string s = "1432219";
    int K = 3;

    cout << sol.function(s, K) << endl; // Expected: "1219"
}
