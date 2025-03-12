#include <iostream>
#include<vector>
#include<algorithm>
using namespace std;
class solution {
    public:
    vector<vector<int>> mergeIntervals(vector<vector<int>> &arr){
        if (arr.empty()) return {}; // Handle empty input

        // Sort the intervals based on the start time
        sort(arr.begin(), arr.end());

        vector<vector<int>> ans;
        ans.push_back(arr[0]); // Add first interval to the answer

        for (int i = 1; i < arr.size(); i++) {
            // Get the last interval from ans
            vector<int>& last = ans.back();

            // If the current interval overlaps, merge it
            if (arr[i][0] <= last[1]) {
                last[1] = max(last[1], arr[i][1]);  // Merge intervals
            } else {
                ans.push_back(arr[i]); // No overlap, add new interval
            }
        }
        return ans;
    
    }
};
int main(){
    cout<<"program executed..."<<endl;
    vector<vector<int>> arr={{1,3},{2,6},{8,10},{15,20}};
    solution sol;
    vector<vector<int>> ans=sol.mergeIntervals(arr);
    int rows=ans.size();
    int columne=ans[0].size();
    if(!ans.empty()){
        for(int i=0;i<rows;i++){
            for(int j=0;j<columne;j++){
                cout<<ans[i][j]<<" ";
            }cout<<endl;
        }
    }

    return 0;
}