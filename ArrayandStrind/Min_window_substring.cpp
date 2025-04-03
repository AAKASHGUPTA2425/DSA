#include <iostream>
#include <unordered_map>
#include <string>
using namespace std;
string minimum_window_substring(string s, string t)
{

    if (s.empty() || t.empty())
        return "";
    unordered_map<char, int> charcount;
    for (char ch : t)
    {
        charcount[ch]++;
    }
    int left = 0, matched = 0, minlength = INT16_MAX, right = 0, startindex = -1;
    int required = charcount.size();
    unordered_map<char, int> Windowcount;
    while (right < s.size())
    {
        char c = s[right];
        Windowcount[c]++;
        if (charcount.count(c) && Windowcount[c] == charcount[c])
        {
            matched++;

            while (matched == required)
            {
                if (right - left + 1 < minlength)
                {
                    minlength = right - left + 1;
                    startindex = left;
                }

                char leftchar = s[left];
                Windowcount[leftchar]--;
                if (charcount.count(leftchar) && Windowcount[leftchar] < charcount[leftchar])
                {
                    matched--;
                    left++;
                }
            }
            right++;
        }
    }
    return (minlength == INT16_MAX) ? "" : s.substr(startindex, minlength);
}

int main()
{
    string s = "SKDJBBASIUDFHAWIJDVNWIHJFOWI";
    string t = "ABW";
    string result = minimum_window_substring(s, t);
    cout << result << endl;
    return 0;
}