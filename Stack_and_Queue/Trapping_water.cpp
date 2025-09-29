#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    int findotal(vector<int> &arr, int n)
    {
        int lmax = 0;
        int rmax = 0;
        int total = 0;
        int r = n - 1;
        int l = 0;

        while (l < r)
        {
            if (arr[l] <= arr[r])
            {
                if (lmax > arr[l])
                {
                    total += lmax - arr[l];
                }
                else
                {
                    lmax = arr[l];
                }
                l = l + 1;
            }
            else
            {
                if (rmax > arr[r])   // ✅ should compare with arr[r], not arr[l]
                {
                    total += rmax - arr[r];
                }
                else
                {
                    rmax = arr[r];
                }
                r = r - 1;
            }
        }
        return total;
    }
};

int main()
{
    Solution sol;
    vector<int> arr = {0,1,0,2,1,0,1,3,2,1,2,1}; // sample input
    int n = arr.size();

    int result = sol.findotal(arr, n);
    cout << "Trapped water: " << result << endl;

    return 0;
}
