#include <iostream>
#include <stack>
using namespace std;

class Solution {
public:
    string postfix_to_prefix(string s) {
        stack<string> st;
        int n = s.size();

        for (int i = 0; i < n; i++) {
            char c = s[i];

            // Operand
            if ((c >= 'A' && c <= 'Z') ||
                (c >= 'a' && c <= 'z') ||
                (c >= '0' && c <= '9')) {
                st.push(string(1, c));
            }
            // Operator
            else {
                string t1 = st.top(); st.pop();
                string t2 = st.top(); st.pop();
                string comp = string(1, c) + t2 + t1;  // prefix = operator + operand1 + operand2
                st.push(comp);
            }
        }

        return st.top();
    }
};

int main() {
    Solution sol;

    string postfix1 = "AB+CD-*";   // ((A+B)*(C-D))
    string postfix2 = "ABC*+D/";   // ((A+(B*C))/D)

    cout << "Postfix: " << postfix1 << " -> Prefix: " << sol.postfix_to_prefix(postfix1) << endl;
    cout << "Postfix: " << postfix2 << " -> Prefix: " << sol.postfix_to_prefix(postfix2) << endl;

    return 0;
}
