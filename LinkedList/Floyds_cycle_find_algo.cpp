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

bool CyclePresent(Node *head)
{
    Node *slow = head;
    Node *fast = head;
    while (fast != NULL && fast->next != NULL)
    {
        slow = slow->next;
        fast = fast->next->next;
        if (fast == slow)
        {
            return true;
        }
    }
    return false;
}
int main()
{
    Node *head = new Node(3);
    head->next = new Node(4);
    head->next->next = new Node(5);
    head->next->next->next = head->next;
    if (CyclePresent)
    {
        cout << "cycle is present" << endl;
    }
    else
    {
        cout << "cycle is not present" << endl;
    }
    return 0;
}
