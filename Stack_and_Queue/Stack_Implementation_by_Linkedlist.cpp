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

class Stack_Implementation
{
private:
    Node *head; // top of stack
    int sz;     // size of stack

public:
    Stack_Implementation()
    {
        head = NULL;
        sz = 0;
    }

    void push(int x)
    {
        Node *temp = new Node(x);
        temp->next = head;
        head = temp;
        sz++;
    }

    void pop()
    {
        if (head == NULL)
        {
            cout << "Stack Underflow!" << endl;
            return;
        }
        Node *temp = head;
        head = head->next;
        delete temp;
        sz--;
    }

    int top()
    {
        if (head == NULL)
        {
            cout << "Stack is Empty!" << endl;
            return -1;
        }
        return head->val;
    }

    int size()
    {
        return sz;
    }

    bool empty()
    {
        return head == NULL;
    }
};
int main()
{
    Stack_Implementation st;

    st.push(10);
    st.push(20);
    st.push(30);

    cout << "Current top: " << st.top() << endl; // 30
    cout << "Stack size: " << st.size() << endl; // 3

    st.pop();
    cout << "After pop, top: " << st.top() << endl; // 20
    cout << "Stack size: " << st.size() << endl;    // 2

    st.pop();
    st.pop();
    cout << "Is stack empty? " << (st.empty() ? "Yes" : "No") << endl;

    st.pop(); // extra pop to test underflow

    return 0;
}
