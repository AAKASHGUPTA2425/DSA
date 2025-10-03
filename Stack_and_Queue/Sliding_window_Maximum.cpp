#include <iostream>
#include <deque>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> Sliding_window(vector<int> &arr, int k) {
        int n = arr.size();
        vector<int> list;   // results
        deque<int> dq;      // stores indices

        for (int i = 0; i < n; i++) {
            // Remove elements out of current window
            if (!dq.empty() && dq.front() <= i - k) {
                dq.pop_front();
            }

            // Remove smaller elements (they can't be max)
            while (!dq.empty() && arr[dq.back()] <= arr[i]) {
                dq.pop_back();
            }

            // Add current index
            dq.push_back(i);

            // Store result when first window is complete
            if (i >= k - 1) {
                list.push_back(arr[dq.front()]);
            }
        }
        return list;
    }
};

int main() {
    Solution sol;

    vector<int> arr = {1, 3, -1, -3, 5, 3, 6, 7};
    int k = 3;

    vector<int> result = sol.Sliding_window(arr, k);

    cout << "Sliding Window Maximums: ";
    for (int x : result) cout << x << " ";
    cout << endl;

    return 0;
}
