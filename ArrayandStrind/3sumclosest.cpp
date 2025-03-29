#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
class Solution {
    public:
      int closest3Sum(vector<int> &arr, int target) {
          // code here
          int n=arr.size();
          sort(arr.begin(),arr.end());
          int closestsum=arr[0]+arr[1]+arr[2];
          for(int i=0;i<n-2;i++){
              int left=i+1,right=n-1;
              while(left<right){
                  int sum=arr[i]+arr[left]+arr[right];
                  if(sum==target)return sum;
                  
                  if (abs(target - sum) < abs(target - closestsum) || 
                   (abs(target - sum) == abs(target - closestsum) && sum > closestsum)) {
                         closestsum = sum;
                                      }
  
                  
                  if(target<sum){
                      right--;
                  }
                  else{
                      left ++;
                  }
              }
          }
     return closestsum;
          
      }
  };

int main(){
    cout<<"program started";
    vector<int> arr={-1,2,2,4};
   int n=arr.size();
    int target=4;
    Solution sol;
    int closestsum=sol.closest3Sum(arr,target);
    cout<<"[";
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    cout<<"]"<<endl;
     cout<<"nearest sum is "<<closestsum;

}