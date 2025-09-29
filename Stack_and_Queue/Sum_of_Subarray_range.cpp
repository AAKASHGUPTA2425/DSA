#include <iostream>
#include <stack>
#include <vector>
using namespace std;

class Solution
{
private:
    // Next Smaller Element
    vector<int> findNSE(vector<int> &arr, int n)
    {
        vector<int> nse(n, n);
        stack<int> st;
        for (int i = n - 1; i >= 0; i--)
        {
            while (!st.empty() && arr[st.top()] >= arr[i])
            {
                st.pop();
            }
            nse[i] = st.empty() ? n : st.top();
            st.push(i);
        }
        return nse;
    }

    // Previous Smaller or Equal Element
    vector<int> findpsee(vector<int> &arr, int n)
    {
        vector<int> psee(n, -1);
        stack<int> st;
        for (int i = 0; i < n; i++)
        {
            while (!st.empty() && arr[st.top()] > arr[i])
            {
                st.pop();
            }
            psee[i] = st.empty() ? -1 : st.top();
            st.push(i);
        }
        return psee;
    }

    // Next Greater Element
    vector<int> findNGE(vector<int> &arr, int n)
    {
        vector<int> nge(n, n);
        stack<int> st;
        for (int i = n - 1; i >= 0; i--)
        {
            while (!st.empty() && arr[st.top()] <= arr[i])
            {
                st.pop();
            }
            nge[i] = st.empty() ? n : st.top();
            st.push(i);
        }
        return nge;
    }

    // Previous Greater Element
    vector<int> findPLEE(vector<int> &arr, int n)
    {
        vector<int> plee(n, -1);
        stack<int> st;
        for (int i = 0; i < n; i++)
        {
            while (!st.empty() && arr[st.top()] < arr[i])
            {
                st.pop();
            }
            plee[i] = st.empty() ? -1 : st.top();
            st.push(i);
        }
        return plee;
    }

    // Sum of subarray minimums
    int sum_min(vector<int> &arr, int n)
    {
        vector<int> nse = findNSE(arr, n);
        vector<int> psee = findpsee(arr, n);
        long long total = 0;
        int mod = 1e9 + 7;
        for (int i = 0; i < n; i++)
        {
            long long left = i - psee[i];
            long long right = nse[i] - i;
            total = (total + (right * left % mod * arr[i]) % mod) % mod;
        }
        return (int)total;
    }

    // Sum of subarray maximums
    int sum_max(vector<int> &arr, int n)
    {
        vector<int> nge = findNGE(arr, n);
        vector<int> plee = findPLEE(arr, n);
        long long total = 0;
        int mod = 1e9 + 7;
        for (int i = 0; i < n; i++)
        {
            long long left = i - plee[i];
            long long right = nge[i] - i;
            total = (total + (right * left % mod * arr[i]) % mod) % mod;
        }
        return (int)total;
    }

public:
    // Final answer = sum(max) - sum(min)
    int sum_range(vector<int> &arr, int n)
    {
        return (sum_max(arr, n) - sum_min(arr, n) + (int)(1e9 + 7)) % (int)(1e9 + 7);
    }
};

int main()
{
    Solution sol;

    // Example test
    vector<int> arr = {1, 2, 3,4};
    int n = arr.size();

    int result = sol.sum_range(arr, n);
    cout << "Sum of Subarray Ranges: " << result << endl;

    return 0;
}
