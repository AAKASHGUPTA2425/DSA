#include <iostream>
#include<vector>
using namespace std;
class Solution{
    public:
    int MaxContainer(vector<int>&height){
        int maxcont=0;
        int left=0,right=(height.size())-1;
        while(left<right){
          int  h=min(height[left],height[right]);
          int width=right-left;
          maxcont=max(maxcont,h*width);
          if(height[left]<height[right]){
             left++;
          }
          else{
            right--;
          }
        }
        return maxcont;

    }
};
int main(){
    cout<<"programme executed....";
    vector<int> height={1,8,6,2,5,4,8,3,7};
    Solution sol;
    int maxcontainer=sol.MaxContainer(height);
    cout<<maxcontainer<<endl;
    return 0;
}