#include <iostream>
#include <vector>
#include <unordered_map>
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
class solution
{
public:
    unordered_map<int, int> inordermap;
    int preindex = 0;
    treenode *buildtree(vector<int> preorder, vector<int> inoder)
    {
        int n = preorder.size();
        for (int i = 0; i < n; ++i)
        {
            inordermap[inoder[i]] = i;
        }
        return build(preorder, 0, n - 1);
    }
    treenode *build(vector<int> preorder, int instart, int inend)
    {
        if (instart > inend)
            return NULL;

        int rootval = preorder[preindex++];
        treenode *root = new treenode(rootval);
        int inindex = inordermap[rootval];
        root->left = build(preorder, instart, inindex - 1);
        root->right = build(preorder, inindex + 1, inend);
        return root;
    }
};
void print(treenode *root)
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
    vector<int> preorder = {3, 1, 2, 4, 5, 6, 7};
    vector<int> inorder = {1, 3, 4, 2, 6, 5, 7};
    solution sol;
    treenode *root;
    root = sol.buildtree(preorder, inorder);
    print(root);
    return 0;
}