#include <iostream>
#include <stack>
using namespace std;
class Node
{
public:
    int val;
    Node *next;
    Node *prev;
    Node *child;
    Node(int data)
    {
        val = data;
        next = NULL;
        prev = NULL;
        child = NULL;
    }
};

Node *Flatten(Node *head)
{
    if (!head)
        return head;
    Node *curr = head;
    stack<Node *> st;
    while (curr)
    {
        if (curr->child)
        {
            if (curr->next)
            {
                st.push(curr->next);
            }
            curr->next = curr->child;
            curr->child->prev = curr;
            curr->child = NULL;
        }

        if (!curr->next && !st.empty())
        {
            Node *temp = st.top();
            st.pop();
            curr->next = temp;
            temp->prev = curr;
        }
        curr = curr->next;
    }
    return head;
}
void printList(Node *head)
{
    Node *curr = head;
    while (curr)
    {
        cout << curr->val << " ";
        curr = curr->next;
    }
    cout << endl;
}
int main()
{
    Node *head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);
    head->next->next->next = new Node(4);
    head->next->next->next->next = new Node(5);
    head->next->next->next->next->next = new Node(6);
    head->next->next->next->next->next->next = NULL;

    head->child = NULL;
    head->next->child = NULL;
    head->next->next->child = new Node(7);
    head->next->next->next->child = NULL;
    head->next->next->next->next->child = NULL;
    head->next->next->next->next->next->child = NULL;

    head->next->prev = head;
    head->next->next->prev = head->next;
    head->next->next->next->prev = head->next->next;
    head->next->next->next->next->prev = head->next->next->next;
    head->next->next->next->next->next->prev = head->next->next->next->next;

    head->next->next->child->next = new Node(8);
    head->next->next->child->next->next = new Node(9);
    head->next->next->child->next->next->next = new Node(10);
    head->next->next->child->next->next->next->next = NULL;

    head->next->next->child->prev = NULL;
    head->next->next->child->next->prev = head->next->next->child;
    head->next->next->child->next->next->prev = head->next->next->child->next;
    head->next->next->child->next->next->next->prev = head->next->next->child->next->next;

    head->next->next->child->child = NULL;
    head->next->next->child->next->child = new Node(11);
    head->next->next->child->next->next->child = NULL;
    head->next->next->child->next->next->next->child = NULL;

    head->next->next->child->next->child->prev = NULL;
    head->next->next->child->next->child->next = new Node(12);
    head->next->next->child->next->child->next->prev = head->next->next->child->next->child;
    head->next->next->child->next->child->next->child = NULL;
    head->next->next->child->next->child->child = NULL;

    Node *newhead = Flatten(head);
    printList(newhead);
    return 0;
}
