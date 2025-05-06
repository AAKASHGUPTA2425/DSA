#include <iostream>
using namespace std;
class Treenode
{
public:
    int val;
    Treenode *left;
    Treenode *right;
    Treenode(int data)
    {
        val = data;
        left = NULL;
        right = NULL;
    }
};

Treenode *inverttree(Treenode *root)
{
    if (root == NULL)
        return NULL;
    Treenode *l = inverttree(root->left);
    Treenode *r = inverttree(root->right);
    root->left = r;
    root->right = l;
    return root;
}
void print(Treenode *root)
{
    if (root == NULL)
        return;
    cout << root->val << ":";
    if (root->left != NULL)
    {
        cout << "L" << root->left->val << ",";
    }
    if (root->right != NULL)
    {
        cout << "R" << root->right->val << ",";
    }
    cout << endl;
    print(root->left);
    print(root->right);
    return;
}
int main()
{
    Treenode *root = new Treenode(4);
    root->left = new Treenode(2);
    root->right = new Treenode(7);
    root->right->left = new Treenode(8);
    root->right->right = new Treenode(9);
    root->left->left = new Treenode(1);
    root->left->right = new Treenode(3);
    Treenode *root2 = inverttree(root);
    print(root2);
    return 0;
}