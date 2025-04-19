#include <iostream>
using namespace std;
class Node
{
public:
    int val;
    Node *next;
    Node *random;
    Node(int data)
    {
        val = data;
        next = NULL;
        random = NULL;
    }
};
Node *copyllwithrandom(Node *head)
{
    if (head == NULL)
        return NULL;

    Node *curr = head;
    while (curr)
    {
        Node *copy = new Node(curr->val);
        copy->next = curr->next;
        curr->next = copy;
        curr = copy->next;
        // main aim to form the linkedlist in A->A'->B->B'->C->C'......
    }
//Assign random pointers
    curr = head;
    while (curr) {
        if (curr->random)
            curr->next->random = curr->random->next;
        curr = curr->next->next;
    }

    // Separate the copied list from the original
    Node *dummyhead = new Node(0);
    Node *copycurr = dummyhead;
    curr = head;
    while (curr)
    {
        copycurr->next = curr->next;
        curr->next = curr->next->next;

        copycurr = copycurr->next;
        curr = curr->next;
    }

    return dummyhead->next;
}

int main()
{
    Node *head = new Node(7);
    head->next = new Node(13);
    head->next->next = new Node(11);
    head->next->next->next = new Node(10);
    head->next->next->next->next = new Node(9);
    head->random = nullptr;
    head->next->random = head;
    head->next->next->random = head->next;
    head->next->next->next->random = head->next->next->next->next;
    head->next->next->next->next->random = head->next->next;
    Node *copyll = copyllwithrandom(head);
    while (copyll)
    {
        cout << copyll->val << "->";
        copyll=copyll->next;
    }
    cout << "NULL";
    return 0;
}