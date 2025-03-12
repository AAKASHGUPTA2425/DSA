#include <iostream>
#include <vector>
using namespace std;
class solution{
    public:
    int minimumvalue(vector<int> &arr){
   int n=arr.size();
   int minElement=INT16_MAX;
   for(int i=0;i<n;i++){
    if(arr[i]<minElement){
        minElement=arr[i];
    }
   }
   return minElement;
    }
};
int main(){
    cout<<"program executed"<<endl;
   vector<int> arr={7,1,2,3,4,5,6};
   solution sol;
   int minElement=sol.minimumvalue(arr);

  if(minElement){
    cout<<minElement<<endl;
   }
   return 0;
}