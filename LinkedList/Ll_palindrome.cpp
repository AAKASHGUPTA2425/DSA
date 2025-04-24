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
bool palindromell(Node *head)
{
    Node *slow = head, *fast = head;
    while (fast && fast->next)
    {
        slow = slow->next;
        fast = fast->next->next;
    }
    Node *prev = NULL;
    while (slow)
    {
        Node *nexttemp = slow->next;
        slow->next = prev;
        prev = slow;
        slow = nexttemp;
    }

    Node *left = head;
    Node *right = prev;
    while (right)
    {
        if (left->val != right->val)
            return false;
        left = left->next;
        right = right->next;
    }
    return true;
}
int main()
{
    Node *head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);
    head->next->next->next = new Node(2);
    head->next->next->next->next = new Node(1);
    bool result = palindromell(head);
    cout << result;
    return 0;
}