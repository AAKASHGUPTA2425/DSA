#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    int priority(char s) {
        if (s == '^') return 3;
        else if (s == '*' || s == '/') return 2;
        else if (s == '+' || s == '-') return 1;
        return -1;
    }
public:
    string infixToPostfix(string& s) {
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
                if (!st.empty()) st.pop(); // pop '('
            }
            // Operator
            else {
                while (!st.empty() &&
                       ((c == '^' && priority(c) < priority(st.top())) ||   // right-assoc
                        (c != '^' && priority(c) <= priority(st.top())))) { // left-assoc
                    ans += st.top();
                    st.pop();
                }
                st.push(c);
            }
        }

        // Pop remaining operators
        while (!st.empty()) {
            ans += st.top();
            st.pop();
        }

        return ans;
    }
};
int main() {
    Solution sol;
    string expr1 = "a+b*c";
    string expr2 = "(a+b)*c";
    string expr3 = "a+b*(c^d-e)^(f+g*h)-i";
    string expr4 = "a^b^c";

    cout << sol.infixToPostfix(expr1) << endl; // abc*+
    cout << sol.infixToPostfix(expr2) << endl; // ab+c*
    cout << sol.infixToPostfix(expr3) << endl; // abcd^e-fgh*+^*+i-
    cout << sol.infixToPostfix(expr4) << endl; // abc^^
}
