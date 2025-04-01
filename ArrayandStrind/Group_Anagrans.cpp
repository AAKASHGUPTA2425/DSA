#include<iostream>
#include<vector>
#include<unordered_map>
#include<string>
using namespace std;
vector<vector<string>> Group_Anagram(vector<string> strs){
vector<unordered_map<char,int>> Mymaps(strs.size());
vector<vector<string>> s;
int n=strs.size();
for(int i=0;i<n;i++){
    for(char ch:strs[i]){
        Mymaps[i][ch]++;
    }
}
vector<bool> visited(n,false);
for(int i=0;i<n;i++){
    if(visited[i])continue;


    vector<string> group;
    group.push_back(strs[i]);
    visited[i]=true;

    for(int j=0;j<n;j++){
        if(!visited[j] && Mymaps[i]==Mymaps[j]){
         group.push_back(strs[j]);
         visited[j]=true;
        }
    }
    s.push_back(group);
}
return s;
}

int main(){
    vector<string> strs={"eat","ate","tan","tea","nat","bat"};
    vector<vector<string>> result=Group_Anagram(strs);
    for (const auto& group : result) {
        cout << "[ ";
        for (const auto& word : group) {
            cout << word << " ";
        }
        cout << "]\n";
    }
    return 0;
}