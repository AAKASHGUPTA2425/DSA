#include<iostream>
#include<stack>
using namespace std;

class Solution {
  public:
    string postToInfix(string exp) {
        stack<string> st;   // stack of strings
        int n = exp.size();

        for (int i = 0; i < n; i++) {
            char c = exp[i];

            // Operand (letter or digit)
            if ((c >= 'A' && c <= 'Z') ||
                (c >= 'a' && c <= 'z') ||
                (c >= '0' && c <= '9')) {
                st.push(string(1, c));  // convert char to string
            }
            // Operator
            else {
                string t1 = st.top(); st.pop();
                string t2 = st.top(); st.pop();
                string comp = "(" + t2 + c + t1 + ")";
                st.push(comp);
            }
        }

        return st.top();
    }
};
int main() {
    Solution sol;
    string exp = "ab+c*";  // postfix
    cout << sol.postToInfix(exp) << endl;
    return 0;
}
