#include <iostream>
#include<vector>
using namespace std;
class Solution {
    public:
        vector<int> productExceptSelf(vector<int>& nums) {
            int n=nums.size();
            int right=1,left=1;
            vector<int> arr(n,1);
            for(int i=0;i<n;i++){
              arr[i] =left;
              left*=nums[i];
            }
            for(int i=n-1;i>=0;i--){
                arr[i]*=right;
                right*=nums[i];
            }
            return arr;
        }
    };

int main() {
    cout<<"program executed..."<<endl;
    vector<int> nums={1,2,3,4};
      Solution sol;
      vector<int> arr=sol.productExceptSelf(nums);
      int n=arr.size();
      if (!arr.empty()) {
        for(int i=0;i<n;i++){
            cout<<arr[i]<<"  "<<endl;
        }
    } else {
        cout << "No solution found!" << endl;
    }

    return 0;
}  
