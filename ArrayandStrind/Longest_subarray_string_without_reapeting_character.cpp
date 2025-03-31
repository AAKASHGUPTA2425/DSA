#include <iostream>
#include <unordered_set>
using namespace std;
int longestsubarray(string s)
{
    unordered_set<char> str;
    int left = 0;
    int maxlength = 0;
    for (int right = 0; right < s.size(); right++)
    {

        while (str.find(s[right]) != str.end())
        {
            str.erase(s[left]);
            left++;
        }

        str.insert(s[right]);

        maxlength = max(maxlength, right - left + 1);
    }
    return maxlength;
}
int main()
{
    string s = "pwwkew";
    int maxlegth = longestsubarray(s);
    cout << s << endl;
    cout << "maximum length of subarray with no reapeting element is =" << maxlegth << endl;
    return 0;
}