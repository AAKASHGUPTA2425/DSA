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
        next = nullptr;
    }
};
Node *Add2Numbers(Node *l1, Node *l2)
{
    Node *dummyhead = new Node(0);
    Node *curr = dummyhead;
    int carry = 0;
    while (l1 != nullptr || l2 != nullptr || carry != 0)
    {
        int x = (l1 != nullptr) ? l1->val : 0;
        int y = (l2 != nullptr) ? l2->val : 0;
        int sum = x + y + carry;

        carry = sum / 10;
        curr->next = new Node(sum % 10);
        curr = curr->next;
        if (l1 != nullptr)
            l1 = l1->next;
        if (l2 != nullptr)
            l2 = l2->next;
    }
    return dummyhead->next;
}

int main()
{
    Node *l1 = new Node(2);
    l1->next = new Node(4);
    l1->next->next = new Node(3);
    Node *l2 = new Node(5);
    l2->next = new Node(6);
    l2->next->next = new Node(4);
    Node *result = Add2Numbers(l1, l2);
    while (result != 0)
    {
        cout << result->val << "->";
        result = result->next;
    }
    cout << "Null" << endl;
    return 0;
}