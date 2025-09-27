#include <iostream>
#include <stack>
using namespace std;

class Solution {
public:
    string prefix_to_postfix(string s) {
        stack<string> st;
        int n = s.size();

        // Traverse from right to left
        for (int i = n - 1; i >= 0; i--) {
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

                // Postfix: operand1 operand2 operator
                string comp = t1 + t2 + string(1, c);
                st.push(comp);
            }
        }
        return st.top();
    }
};

int main() {
    Solution sol;

    string prefix1 = "*+AB-CD";   // ((A+B)*(C-D))
    string prefix2 = "/+A*BCD";   // (A + (B*C)) / D

    cout << "Prefix: " << prefix1 << " -> Postfix: " 
         << sol.prefix_to_postfix(prefix1) << endl;

    cout << "Prefix: " << prefix2 << " -> Postfix: " 
         << sol.prefix_to_postfix(prefix2) << endl;

    return 0;
}
