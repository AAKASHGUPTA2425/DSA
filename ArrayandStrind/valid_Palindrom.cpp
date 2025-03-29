#include <iostream>
#include <cctype>
using namespace std;

bool isvalidPalindrome(string s)
{
    int l = 0, r = s.size() - 1;
    while (l < r)
    {
        while (l < r && !isalnum(s[l]))
            l++;
        while (l < r && !isalnum(s[r]))
            r--;

        if (tolower(s[l]) != tolower(s[r]))
        {
            return false;
        }
        l++;
        r--;
    }
    return true;
}
int main()
{
    string str = "A man, a plan, a canal: Panama";
    string str2= "AAKASH GUPTA";
    cout << (isvalidPalindrome(str) ? "palindrome" : "no palindrome")<<endl;
    cout << (isvalidPalindrome(str2) ? "palindrome" : "no palindrome")<<endl;
    return 0;
}