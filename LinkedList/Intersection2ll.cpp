#include <iostream>
using namespace std;
class Node
{
public:
    int val;
    Node *next = NULL;
    Node(int data)
    {
        val = data;
        next = NULL;
    }
};
Node *Intersection2ll(Node *head1, Node *head2)
{
    if (head1 == NULL && head2 == NULL)
        return NULL;
    int l1 = 0, l2 = 0;
    Node *temp1 = head1;
    Node *temp2 = head2;
    Node *ptr1;
    Node *ptr2;
    while (temp1 != NULL)
    {
        l1 += 1;
        temp1 = temp1->next;
    }
    while (temp2 != NULL)
    {
        l2 += 1;
        temp2 = temp2->next;
    }
    if (l1 > l2)
    {
        ptr1 = head1;
        int k = l1 - l2;
        while (k--)
        {
            ptr1 = ptr1->next;
        }
        ptr2 = head2;
    }
    else if (l1 < l2)
    {
        ptr2 = head2;
        int k = l2 - l1;
        while (k--)
        {
            ptr2 = ptr2->next;
        }
        ptr1 = head1;
    }
    while (ptr1)
    {
        if (ptr1 == ptr2)
        {
            return ptr1;
        }
        ptr1 = ptr1->next;
        ptr2 = ptr2->next;
    }
}
int main()
{
    Node *head1 = new Node(1);
    head1->next = new Node(2);
    head1->next->next = new Node(3);
    head1->next->next->next = new Node(4);
    head1->next->next->next->next = new Node(5);
    Node *head2 = new Node(6);
    head2->next = head1->next->next->next;
    head2->next->next = new Node(5);
    Node *result = Intersection2ll(head1, head2);
    if (result)
    {
        cout << "Intersection is:" << result->val;
    }
    else
    {
        cout << "no intersection";
    }
    return 0;
}