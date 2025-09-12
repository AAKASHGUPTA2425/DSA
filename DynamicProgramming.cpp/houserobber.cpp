#include<iostream>
#include<vector>
using namespace std;
class Solution{
private:
int maximumadjacentsum(vector<int>&nums){
    int n=nums.size();
    int prev=nums[0];
    int prev2=0;
    for(int j=0;j<n;j++){
        int take=nums[j];
        if(j>1)take+=prev2;
        int nottake=0+prev;
        int curi=max(take,nottake);
        prev2=prev;
        prev=curi;
    }
}
public:
  int houserobber(vector<int>valuehouse){
    int n=valuehouse.size();
    vector<int>temp1,temp2;
    for(int j=0;j<n;j++){
        if(j!=0)temp1.push_back(valuehouse[j]);
        if(j!=n-1)temp2.push_back(valuehouse[j]);
        
    }
    return max(maximumadjacentsum(temp1),maximumadjacentsum(temp2));
  }
};


int main() {
    Solution sol;

    // Example input
    vector<int> nums = {9,2,3,1,5};

    // Output the minimum cost
    cout << "Maximum houserobber: " << sol.houserobber(nums) << endl;

    return 0;
}
