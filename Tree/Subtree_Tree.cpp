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
class Subtree
{
public:
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
    bool subtree(treenode *root, treenode *subroot)
    {
        if (root == NULL)
            return false;
        if (Sametree(root, subroot))
        {
            return true;
        }

        return Sametree(root->left, subroot) || Sametree(root->right, subroot);
    }
};
int main()
{
    treenode *roota = new treenode(1);
    roota->left = new treenode(2);
    roota->right = new treenode(3);
    roota->left->left = new treenode(4);
    roota->left->right = new treenode(5);

    treenode *rootB = roota->left;
    rootB->left = roota->left->left;
    rootB->right = roota->left->right;
    Subtree ss;
    bool result = ss.subtree(roota, rootB);
    cout << result;
    return 0;
}