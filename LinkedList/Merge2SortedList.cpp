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
Node *merge2sortedlist(Node *list1, Node *list2)
{
    if (!list1)
        return list2;
    if (!list2)
        return list1;

    if (list1->val < list2->val)
    {
        list1->next = merge2sortedlist(list1->next, list2);
        return list1;
    }
    else
    {
        list2->next = merge2sortedlist(list1, list2->next);
        return list2;
    }
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
    Node *head1 = new Node(1);
    head1->next = new Node(3);
    head1->next->next = new Node(5);
    head1->next->next->next = new Node(6);
    Node *head2 = new Node(2);
    head2->next = new Node(3);
    head2->next->next = new Node(4);
    head2->next->next->next = new Node(5);
    Node *result = merge2sortedlist(head1, head2);
    Display(result);
    return 0;
}