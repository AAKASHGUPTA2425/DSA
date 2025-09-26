#include <iostream>
#include <stack>
using namespace std;
class Solution
{
public:
    bool Check_Parenthesis(string &s)
    {
        stack<char> st;
        int n = s.size();
        for (int i = 0; i < n; i++)
        {
            if (s[i] == '(' || s[i] == '{' || s[i] == '[')
            {
                st.push(s[i]);
            }
            else
            {
                if (st.empty())
                    return false;
                char ch = st.top();
                st.pop();
                if ((s[i] == ')' && ch != '(') ||
                    (s[i] == ']' && ch != '[') ||
                    (s[i] == '}' && ch != '{'))
                {
                    return false;
                }
            }
        }
        return st.empty();
    }
};
int main()
{
    Solution sol;
    string s1 = "{[()]}";
    string s2 = "{[(])}";
    string s3 = "(()[]){}";

    cout << sol.Check_Parenthesis(s1) << endl; // 1 (true)
    cout << sol.Check_Parenthesis(s2) << endl; // 0 (false)
    cout << sol.Check_Parenthesis(s3) << endl; // 1 (true)
}
