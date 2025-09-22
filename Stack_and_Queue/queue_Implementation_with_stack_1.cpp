#include <iostream>
#include <stack>
using namespace std;

class QueueUsingTwoStacks {
    stack<int> s1, s2;

public:
    // Push element (always in s1)
    void push(int x) {
        s1.push(x);
    }

    // Remove front element
    void pop() {
        if (s1.empty() && s2.empty()) {
            cout << "Queue Underflow!" << endl;
            return;
        }

        if (s2.empty()) {
            // Move all elements from s1 -> s2
            while (!s1.empty()) {
                s2.push(s1.top());
                s1.pop();
            }
        }
        s2.pop();
    }

    // Get front element
    int front() {
        if (s1.empty() && s2.empty()) {
            cout << "Queue is Empty!" << endl;
            return -1;
        }

        if (s2.empty()) {
            // Move all elements from s1 -> s2
            while (!s1.empty()) {
                s2.push(s1.top());
                s1.pop();
            }
        }
        return s2.top();
    }

    // Check empty
    bool empty() {
        return (s1.empty() && s2.empty());
    }
};

int main() {
    QueueUsingTwoStacks q;

    q.push(10);
    q.push(20);
    q.push(30);

    cout << "Front: " << q.front() << endl;  // 10
    q.pop();
    cout << "Front: " << q.front() << endl;  // 20

    q.pop();
    q.pop();
    cout << "Is empty? " << (q.empty() ? "Yes" : "No") << endl;

    q.pop(); // extra pop to test underflow

    return 0;
}
