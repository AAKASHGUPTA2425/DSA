#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;
class LRU_Cache
{
public:
    class Node
    {
    public:
        int val;
        int key;
        Node *next;
        Node *prev;
        Node(int key, int val)
        {
            this->val = val;
            this->key = key;
            next = NULL;
            prev = NULL;
        }
    };

    Node *head = new Node(-1, -1);
    Node *tail = new Node(-1, -1);
    unordered_map<int, Node *> m;
    int limit;
    void addnode(Node *newnode)
    {
        Node *oldnext = head->next;
        head->next = newnode;
        newnode->prev = head;
        newnode->next = oldnext;
        oldnext->prev = newnode;
    }
    void delnode(Node *oldnode)
    {
        Node *prevnode = oldnode->prev;
        Node *nextnode = oldnode->next;
        prevnode->next = nextnode;
        nextnode->prev = prevnode;
    }

    LRU_Cache(int capacity) /*it is just forming the ll basic structure*/
    {
        limit = capacity;
        head->next = tail;
        tail->prev = head;
    }
    int get(int key) /*this function is returning the value present in the unordered_map and if its present in the map then it move the key to just after the head of the doubly ll */
    {
        if (m.find(key) == m.end())
        {
            return -1;
        }
        Node *node = m[key];
        delnode(node);
        addnode(node);
        m[key] = head->next;

        return node->val;
    }
    int put(int key, int val) /*the aim of this function is to add a new node just after the head (-1,-1) either it present in the doubly ll or not, it just add*/
    {
        if (m.find(key) != m.end())
        {
            Node *oldnode = m[key];
            m.erase(key);
            delnode(oldnode);
        }
        if (m.size() == limit)
        {
            m.erase(tail->prev->key);
            delnode(tail->prev);
        }
        Node *newnode = new Node(key, val);
        addnode(newnode);
        m[key] = newnode;
    }
};

int main()
{
    vector<int> result;
    LRU_Cache lruCache = LRU_Cache(2);
    lruCache.put(1, 1);
    lruCache.put(2, 2);
    result.push_back(lruCache.get(1)); // return 1
    lruCache.put(3, 3);                // LRU key was 2, evicts key 2, cache is {1=1, 3=3}
    result.push_back(lruCache.get(2)); // returns -1 (not found)
    lruCache.put(4, 4);                // LRU key was 1, evicts key 1, cache is {4=4, 3=3}
    result.push_back(lruCache.get(1)); // return -1 (not found)
    result.push_back(lruCache.get(3)); // return 3
    result.push_back(lruCache.get(4));
    for (int i = 0; i < result.size(); i++)
    {
        cout << result[i] << " ";
    }
    cout << endl;
    return 0;
}