#include<iostream>
using namespace std;

string LongPalindromeSubstr(string s){
int start=0;
int Maxlength=1;
auto expandAroundCenter=[&](int left,int right){//lambda function: it is a 1 line function which take value in refrence when we use "&" operator or if we use "=" then it will work as a value by function 
    while(left>=0&&right<s.size()&&s[left]==s[right]){
        if(right-left+1>Maxlength){
            start=left;
            Maxlength=right-left+1;

        }
        left--;
        right++;
    }
};
for(int i=0;i<s.size();i++){
expandAroundCenter(i,i);
expandAroundCenter(i,i+1);
}
return s.substr(start,Maxlength);
}
int main(){
    string s="abbase";
    string subs=LongPalindromeSubstr(s);
    cout<<"longest palindrome substring is = "<<subs;
}