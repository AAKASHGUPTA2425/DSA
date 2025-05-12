#include <iostream>
using namespace std;
class treenode
{
public:
    int val;
    treenode *left;
    treenode *right;
    treenode(int data)
    {
        val = data;
        left = NULL;
        right = NULL;
    }
};
bool Sametree(treenode *roota, treenode *rootb)
{
    if (roota == NULL && rootb == NULL)
        return true;
    if (roota == NULL || rootb == NULL)
        return false;
    if (roota->val != rootb->val)
    {
        return false;
    }
    return Sametree(roota->left, rootb->left) && Sametree(roota->right, rootb->right);
}

int main()
{
    treenode *roota = new treenode(1);
    roota->left = new treenode(2);
    roota->right = new treenode(3);
    roota->left->left = new treenode(4);
    roota->left->right = new treenode(5);

    treenode *rootB = new treenode(1);
    rootB->left = new treenode(2);
    rootB->right = new treenode(3);
    rootB->left->left = new treenode(4);
    rootB->left->right = new treenode(5);
    bool result = Sametree(roota, rootB);
    cout << result;
    return 0;
}