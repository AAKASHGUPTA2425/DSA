#include <iostream>
using namespace std;

class stackImplementation {
public:
    int t = -1;      // stack top index
    int st[10];      // stack array

    void push(int x) {
        if (t >= 9) {   // max size = 10
            cout << "Stack Overflow!" << endl;
            return;
        }
        t = t + 1;
        st[t] = x;
    }

    int top() {
        if (t == -1) {
            cout << "Stack is Empty!" << endl;
            return -1;
        }
        return st[t];
    }

    void pop() {
        if (t == -1) {
            cout << "Stack Underflow!" << endl;
            return;
        }
        t = t - 1;
    }

    int size() {
        return t + 1;
    }

    bool empty() {
        return (t == -1);
    }
};

int main() {
    stackImplementation s;

    // Push elements
    s.push(10);
    s.push(20);
    s.push(30);

    cout << "Current top: " << s.top() << endl;   // should print 30
    cout << "Stack size: " << s.size() << endl;   // should print 3

    s.pop();
    cout << "After pop, top: " << s.top() << endl;  // should print 20

    s.pop();
    s.pop();
    cout << "After popping all, is empty? " << (s.empty() ? "Yes" : "No") << endl;

    return 0;
}
