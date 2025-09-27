#include <iostream>
#include <stack>
using namespace std;

class Solution {
public:
    string Prefix_to_Infix(string exp) {
        stack<string> st;
        int n = exp.size();

        for (int i = n - 1; i >= 0; i--) {  // include 0th index
            char c = exp[i];

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
                string comp = "(" + t1 + c + t2 + ")";
                st.push(comp);
            }
        }

        return st.top();
    }
};

int main() {
    Solution sol;

    string prefix1 = "*+AB-CD";   // equivalent to ((A+B)*(C-D))
    string prefix2 = "+*ABC";     // equivalent to ((A*B)+C)

    cout << "Prefix: " << prefix1 << " -> Infix: " << sol.Prefix_to_Infix(prefix1) << endl;
    cout << "Prefix: " << prefix2 << " -> Infix: " << sol.Prefix_to_Infix(prefix2) << endl;

    return 0;
}
