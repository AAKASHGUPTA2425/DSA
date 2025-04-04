#include<iostream>
#include<vector>
using namespace std;
int TrappingWater(vector<int> &height){
if(height.size()<=2) return 0;
int left=0,right=height.size()-1;
int leftMax=height[left],rightMax=height[right];
int WaterTrapped=0;
while(left<right){
    if(leftMax<rightMax){
        left++;
        leftMax=max(leftMax,height[left]);
         WaterTrapped+=max(0,leftMax-height[left]);
    }
    else{
        right--;
        rightMax=max(rightMax,height[right]);
        WaterTrapped+=max(0,rightMax-height[right]);
    }
}
return WaterTrapped;
}

int main(){
    vector<int> height={0,1,0,2,1,0,1,3,2,1,2,1};
    int waterTrapped=TrappingWater(height);
    cout<<"total water trapped is "<<waterTrapped;
    return 0;
}