#include <iostream>
#include <vector>
using namespace std;
class Solution {
    public:
        int search(vector<int>& nums, int target) {
            int n=nums.size();
            for(int i=0;i<n;i++){
                if(nums[i]==target){
                    return i;
                }
            }
            return -1;
        }
    };

    int main(){
        cout<<"program executed..."<<endl;
        vector<int> nums={4,5,6,7,0,1,2,3};
        int target=0;
        Solution sol;
       int search =sol.search(nums,target);
       if(search){
        cout<<search<<endl;
       }
       return 0;

    }