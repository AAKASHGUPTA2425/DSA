#include <iostream>
using namespace std;

class Node
{
public:
    int val;
    Node *next;
    Node(int data)
    {
        val = data;
        next = NULL;
    }
};

class Queue_Implementation
{
public:
    Node *start;
    Node *end;
    int sz;

    Queue_Implementation()
    {
        start = NULL;
        end = NULL;
        sz = 0;
    }

    void push(int x)
    {
        Node *temp = new Node(x);
        if (start == NULL)
        { // queue is empty
            start = temp;
            end = temp;
        }
        else
        {
            end->next = temp;
            end = temp;
        }
        sz++;
    }

    void pop()
    {
        if (start == NULL)
        {
            cout << "Queue Underflow!" << endl;
            return;
        }
        Node *temp = start;
        start = start->next;
        if (start == NULL)
            end = NULL; // queue became empty
        delete temp;
        sz--;
    }

    int top()
    {
        if (start == NULL)
        {
            cout << "Queue is Empty!" << endl;
            return -1;
        }
        return start->val;
    }

    int size()
    {
        return sz;
    }

    bool empty()
    {
        return sz == 0;
    }
};
int main()
{
    Queue_Implementation q;

    q.push(10);
    q.push(20);
    q.push(30);

    cout << "Front element: " << q.top() << endl; // 10
    cout << "Queue size: " << q.size() << endl;   // 3

    q.pop();
    cout << "After pop, front: " << q.top() << endl; // 20
    cout << "Queue size: " << q.size() << endl;      // 2

    q.pop();
    q.pop();
    cout << "Is queue empty? " << (q.empty() ? "Yes" : "No") << endl;

    q.pop(); // extra pop to test underflow

    return 0;
}
