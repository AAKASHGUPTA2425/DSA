#include <iostream>
#include <stack>
#include <bits/stdc++.h>
using namespace std;
class Solution
{
private:
    int priority(char s)
    {
        if (s == '^')
            return 3;
        else if (s == '*' || s == '/')
            return 2;
        else if (s == '+' || s == '-')
            return 1;
        else
            return -1;
    }

public:
 string Infix_to_prefix(string &s) {
    // Step 1: Reverse
    reverse(s.begin(), s.end());

    // Step 2: Swap '(' and ')'
    for (int i = 0; i < s.size(); i++) {
        if (s[i] == '(') s[i] = ')';
        else if (s[i] == ')') s[i] = '(';
    }

    stack<char> st;
    string ans = "";
    int n = s.size();

    for (int i = 0; i < n; i++) {
        char c = s[i];

        // Operand
        if ((c >= 'a' && c <= 'z') ||
            (c >= 'A' && c <= 'Z') ||
            (c >= '0' && c <= '9')) {
            ans += c;
        }
        // Opening bracket
        else if (c == '(') {
            st.push(c);
        }
        // Closing bracket
        else if (c == ')') {
            while (!st.empty() && st.top() != '(') {
                ans += st.top();
                st.pop();
            }
            if (!st.empty()) st.pop();
        }
        // Operator
        else {
            while (!st.empty() &&
                   ((c == '^' && priority(c) < priority(st.top())) ||
                    (c != '^' && priority(c) <= priority(st.top())))) {
                ans += st.top();
                st.pop();
            }
            st.push(c);
        }
    }

    while (!st.empty()) {
        ans += st.top();
        st.pop();
    }

    reverse(ans.begin(), ans.end()); // final prefix
    return ans;
}

};

int main()
{
    Solution sol;
    string exp1 = "(a+b)*c";
    string exp2 = "a+b*(c^d-e)^(f+g*h)-i";

    cout << "Prefix of \"" << exp1 << "\" is: " << sol.Infix_to_prefix(exp1) << endl;
    cout << "Prefix of \"" << exp2 << "\" is: " << sol.Infix_to_prefix(exp2) << endl;

    return 0;
}