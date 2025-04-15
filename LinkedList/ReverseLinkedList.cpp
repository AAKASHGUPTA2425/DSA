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
Node *reversel(Node *head)
{
    Node *previousNode = NULL;
    Node *curentNode = head;
    while (curentNode != NULL)
    {
        Node *nextnode = curentNode->next;
        curentNode->next = previousNode;
        previousNode = curentNode;
        curentNode = nextnode;
    }
    Node *new_head = previousNode;
    return new_head;
}

int main()
{
    Node *head = new Node(3);
    head->next = new Node(4);
    head->next->next = new Node(5);
    head->next->next->next = new Node(6);
    head->next->next->next->next = new Node(7);
    head->next->next->next->next->next = new Node(8);
    Node *new_Node = reversel(head);
    Node *curentNode = new_Node;
    while (curentNode != NULL)
    {
        cout << curentNode->val << " ";
        curentNode = curentNode->next;
    }
    cout << endl;

    return 0;
}