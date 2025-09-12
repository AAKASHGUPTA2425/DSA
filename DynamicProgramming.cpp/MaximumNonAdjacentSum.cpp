#include<iostream>
#include<vector>
using namespace std;
class Solution{
private:
int f(int ind,vector<int>&nums,vector<int>&dp){
    if(ind==0)return nums[ind];
    if(ind<0) return 0;
    if(dp[ind]!=-1)return dp[ind];
    int pick=nums[ind]+f(ind-2,nums,dp);
    int notpick=0+f(ind-1,nums,dp);
return dp[ind]=max(pick,notpick);
}
public:
    int Maxnonadjucentsum(vector<int>& nums) {
        int ind = nums.size();
        vector<int> dp(ind, -1);
        return f(ind - 1, nums, dp);
    }
};


int main() {
    Solution sol;

    // Example input
    vector<int> nums = {9,2,3,1,5};

    // Output the minimum cost
    cout << "Maximum non adjcent sum: " << sol.Maxnonadjucentsum(nums) << endl;

    return 0;
}
