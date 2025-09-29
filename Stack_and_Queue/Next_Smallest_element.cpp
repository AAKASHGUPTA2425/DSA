#include <iostream>
#include <stack>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> Nextsmallestelement(vector<int>& arr, int n) {
        vector<int> nse(n, -1);
        stack<int> st;
        for (int i = 0; i < n; i++) {
            while (!st.empty() && st.top() >= arr[i]) {
                st.pop();
            }
            nse[i] = st.empty() ? -1 : st.top();
            st.push(arr[i]);
        }
        return nse;
    }
};

int main() {
    Solution sol;
    vector<int> arr = {4, 8, 5, 2, 25};
    int n = arr.size();

    vector<int> result = sol.Nextsmallestelement(arr, n);

    cout << "Next Smaller Elements:\n";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " -> " << result[i] << endl;
    }

    return 0;
}
