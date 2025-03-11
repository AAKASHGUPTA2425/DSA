#include <iostream>
#include<vector>
using namespace std;
class Solution {
    public:
    
        vector<int> twoSum(vector<int>& nums, int target) {
            int n=nums.size();
            for(int i=0;i<n;i++){
                for(int j=i+1;j<n;j++){
                    int k=nums[i]+nums[j];
                 if(k==target){
                   return {i,j};
                 }
                }
            }
    return {};
     }
    };
    int main() {
        cout << "Program started..." << endl;
    
        vector<int> num = {1, 3, 11, 14, 17, 18};
        int target = 35;
    
        Solution sol;
        vector<int> result = sol.twoSum(num, target);
    
        if (!result.empty()) {
            cout << "Indices: " << result[0] << ", " << result[1] << endl;
        } else {
            cout << "No solution found!" << endl;
        }
    
        return 0;
    }