#include <iostream>
#include <vector>
using namespace std;

class Solution{
    public:
    int Subarraysum(vector<int> &nums,int target){
       int n=nums.size();
       int count=0;
       for(int i=0;i<n;i++){
        int sum=0;
        for(int j=i;j<n;j++){
            sum+=nums[j];
            if(sum==target){
                count++;
            }
        }
       }
   return count; }
};
int main(){
    cout<<"programe executed....."<<endl;
    vector<int> nums={-1,-1,1};
    int target=1;
  int n=nums.size();
   Solution sol;
   int count=sol.Subarraysum(nums,target);
   cout<<"{";
   for(int i=0;i<n;i++){
      cout<<nums[i]<<" ";
   }
   cout<<"}"<<endl;
   cout<<"numbers of subarrayes whose sum is equal to target = "<<count<<endl;
}