#include <iostream>
#include <stack>
using namespace std;

class MinStck {
public:
    stack<int> st;
    int min_i = INT16_MAX;

    void push(int val) {
        if (st.empty()) {
            min_i = val;
            st.push(val);
        } else {
            if (val > min_i) {
                st.push(val);
            } else {
                // encode value
                st.push(2 * val - min_i);
                min_i = val;
            }
        }
    }

    void pop() {
        if (st.empty()) return;
        int x = st.top();
        st.pop();
        if (x < min_i) {
            // decode previous min
            min_i = 2 * min_i - x;
        }
    }

    int top() {
        if (st.empty()) return -1;
        int x = st.top();
        if (x >= min_i) return x;
        return min_i;
    }

    int get_min() {
        if (st.empty()) return -1;
        return min_i;
    }
};

int main() {
    MinStck ms;

    ms.push(5);
    ms.push(3);
    ms.push(7);
    ms.push(2);

    cout << "Current Min: " << ms.get_min() << endl; // 2
    cout << "Top Element: " << ms.top() << endl;    // 2

    ms.pop();
    cout << "After pop -> Min: " << ms.get_min() << endl; // 3
    cout << "Top Element: " << ms.top() << endl;         // 7

    ms.pop();
    cout << "After pop -> Min: " << ms.get_min() << endl; // 3
    cout << "Top Element: " << ms.top() << endl;         // 3

    ms.pop();
    cout << "After pop -> Min: " << ms.get_min() << endl; // 5
    cout << "Top Element: " << ms.top() << endl;         // 5

    return 0;
}
