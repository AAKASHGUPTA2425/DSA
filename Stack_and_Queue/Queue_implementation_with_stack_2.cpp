#include <iostream>
#include <stack>
using namespace std;

class QueueUsingOneStack {
    stack<int> s;

    // Helper function for pop
    int popHelper() {
        if (s.empty()) {
            cout << "Queue Underflow!" << endl;
            return -1;
        }

        int x = s.top();
        s.pop();

        if (s.empty()) {
            // This is the front element
            return x;
        }

        int item = popHelper();
        s.push(x);
        return item;
    }

public:
    void push(int x) {
        s.push(x);
    }

    void pop() {
        int frontElement = popHelper();
        if (frontElement != -1)
            cout << "Popped: " << frontElement << endl;
    }

    int front() {
        int frontElement = popHelper();
        if (frontElement != -1) {
            s.push(frontElement); // restore stack
        }
        return frontElement;
    }

    bool empty() {
        return s.empty();
    }
};

int main() {
    QueueUsingOneStack q;

    q.push(10);
    q.push(20);
    q.push(30);

    cout << "Front: " << q.front() << endl; // 10
    q.pop();                                // removes 10

    cout << "Front: " << q.front() << endl; // 20
    q.pop();                                // removes 20

    cout << "Front: " << q.front() << endl; // 30
    q.pop();                                // removes 30

    cout << "Is empty? " << (q.empty() ? "Yes" : "No") << endl;

    return 0;
}
             