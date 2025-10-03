#include <iostream>
#include <stack>
#include <vector>
using namespace std;

class Solution
{
private:
    int function(vector<int> &arr)
    {
        int n = arr.size();
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

public:
    int max_rectangle(vector<vector<int>> &mat, int n, int m)
    {
        int maxArea = 0;
        vector<vector<int>> psum(n, vector<int>(m));

        // Build prefix sum column-wise (heights for histogram)
        for (int j = 0; j < m; j++)
        {
            int sum = 0;
            for (int i = 0; i < n; i++)
            {
                sum += mat[i][j];
                if (mat[i][j] == 0)
                    sum = 0;
                psum[i][j] = sum;
            }
        }

        // For each row, treat as histogram
        for (int i = 0; i < n; i++)
        {
            maxArea = max(maxArea, function(psum[i]));
        }

        return maxArea;
    }
};

int main()
{
    Solution sol;

    // Example binary matrix
    vector<vector<int>> mat = {
        {0, 1, 1, 0},
        {1, 1, 1, 1},
        {1, 1, 1, 1},
        {1, 1, 0, 0}};

    int n = mat.size();
    int m = mat[0].size();

    cout << "Maximum rectangle of 1's area = " << sol.max_rectangle(mat, n, m) << endl;

    return 0;
}
