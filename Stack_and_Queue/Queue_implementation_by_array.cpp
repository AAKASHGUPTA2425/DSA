#include <iostream>
using namespace std;

class Queue_Implementation {
    int capacity = 10;
    int q[10];
    int currsize = 0;
    int start = -1, end = -1;

public:
    void push(int x) {
        if (currsize == capacity) {
            cout << "Queue Overflow!" << endl;
            return;
        }
        if (currsize == 0) {
            start = 0;
            end = 0;
            q[0] = x;
        } else {
            end = (end + 1) % capacity;
            q[end] = x;
        }
        currsize++;
    }

    void pop() {
        if (currsize == 0) {
            cout << "Queue Underflow!" << endl;
            return;
        }
        if (currsize == 1) {
            start = end = -1;
        } else {
            start = (start + 1) % capacity;
        }
        currsize--;
    }

    int top() {
        if (currsize == 0) {
            cout << "Queue is Empty!" << endl;
            return -1;
        }
        return q[start];
    }

    int size() {
        return currsize;
    }

    bool empty() {
        return currsize == 0;
    }
};

int main() {
    Queue_Implementation q;

    q.push(10);
    q.push(20);
    q.push(30);

    cout << "Front element: " << q.top() << endl;   // 10
    cout << "Queue size: " << q.size() << endl;    // 3

    q.pop();
    cout << "After pop, front element: " << q.top() << endl; // 20
    cout << "Queue size: " << q.size() << endl;             // 2

    q.pop();
    q.pop();
    cout << "Is queue empty? " << (q.empty() ? "Yes" : "No") << endl;

    q.pop(); // extra pop to test underflow

    return 0;
}
