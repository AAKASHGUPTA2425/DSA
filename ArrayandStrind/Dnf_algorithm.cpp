#include<iostream>
#include <vector>
using namespace std;
class Solution{
public:
vector<int> Dnf_algorithm(vector<int> & nums){
    int n=nums.size();
    int low=0,mid=0;
    int high=n-1;
    while(mid<=high){
        switch (nums[mid])
        {
        case 0:
            swap(nums[low],nums[mid]);
            low++;
            mid++;
            break;
        case 1:
            mid++;
            break;
        case 2:
            swap(nums[high],nums[mid]);
            high--;
            break;
        
        default:
            break;
        }
    }

}
};
int main(){
    vector <int> nums={1,2,0,1,0,2,0,1};
    Solution sol;
    sol.Dnf_algorithm(nums);
    for (int i = 0; i < nums.size(); i++)   
    {
        cout<<nums[i]<<" ";
    }
    return 0;
    
}