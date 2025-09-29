#include <iostream>
#include <stack>
#include <vector>
using namespace std;

class Soltion
{
private:
    vector<int> findNSE(vector<int> &arr, int n)
    {
        vector<int> nse(n, -1);
        stack<int> st;
        for (int i = n - 1; i >= 0; i--)
        {
            while (!st.empty() && arr[st.top()] >= arr[i]) // ✅ fixed
            {
                st.pop();
            }
            nse[i] = st.empty() ? n : st.top();
            st.push(i);
        }
        return nse;
    }

    vector<int> findpsee(vector<int> &arr, int n)
    {
        vector<int> psee(n, -1);
        stack<int> st;
        for (int i = 0; i < n; i++) // ✅ iterate full array
        {
            while (!st.empty() && arr[st.top()] > arr[i]) // ✅ fixed
            {
                st.pop();
            }
            psee[i] = st.empty() ? -1 : st.top();
            st.push(i);
        }
        return psee;
    }

public:
    int sum(vector<int> &arr, int n)
    {
        vector<int> nse = findNSE(arr, n);
        vector<int> psee = findpsee(arr, n);
        int total = 0;
        int mod = (int)(1e9 + 7);
        for (int i = 0; i < n; i++)
        {
            int left = i - psee[i];
            int right = nse[i] - i;
            total = (total + (right * 1LL * left * arr[i]) % mod) % mod;
        }
        return total;
    }
};

int main()
{
    Soltion sol;
    vector<int> arr = {3, 1, 2, 4, 7, 5, 4, 3}; // sample test
    int n = arr.size();

    int result = sol.sum(arr, n);
    cout << "Result: " << result << endl;

    return 0;
}
