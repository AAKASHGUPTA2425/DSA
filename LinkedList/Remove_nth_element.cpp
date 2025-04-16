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
Node *RemoveNthElement(Node *head, int n)
{
    Node *ptr1 = head;
    Node *ptr2 = head;
    int count = n;
    while (count--)
    {
        ptr2 = ptr2->next;
    }
    if (ptr2 == NULL)
    {
        Node *temp = head;
        head = head->next;
        delete (temp);
        return head;
    }
    while (ptr2->next != NULL)
    {
        ptr1 = ptr1->next;
        ptr2 = ptr2->next;
    }
    Node *temp = ptr1->next;
    ptr1->next = ptr1->next->next;
    delete (temp);

    return head;
}
void Display(Node *head)
{
    Node *temp = head;
    while (temp != NULL)
    {
        cout << temp->val << "->";
        temp = temp->next;
    }
}
int main()
{
    Node *head = new Node(3);
    head->next = new Node(4);
    head->next->next = new Node(5);
    head->next->next->next = new Node(6);
    head->next->next->next->next = new Node(7);
    head->next->next->next->next->next = new Node(8);
    head->next->next->next->next->next->next = new Node(9);
    int n = 3;
    Node *new_head = RemoveNthElement(head, n);
    Display(new_head);
    return 0;
}
