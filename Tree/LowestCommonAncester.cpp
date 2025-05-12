#include <iostream>
using namespace std;
class TreeNode
{
public:
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int data)
    {
        val = data;
        left = NULL;
        right = NULL;
    }
};

TreeNode *LowestCommonAncester(TreeNode *root, TreeNode *p, TreeNode *q)
{
    if (root == NULL)
        return NULL;

    if (root->val == p->val || root->val == q->val)
    {
        return root;
    }
    TreeNode *LeftNode = LowestCommonAncester(root->left, p, q);
    TreeNode *RightNode = LowestCommonAncester(root->right, p, q);

    if (LeftNode && RightNode)
    {
        return root;
    }
    return (LeftNode != nullptr) ? LeftNode : RightNode;
}

int main()
{
    TreeNode *root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    root->right->left = new TreeNode(6);
    root->right->right = new TreeNode(7);
    root->right->right->left = new TreeNode(8);
    root->right->right->right = new TreeNode(9);
    TreeNode *ans = LowestCommonAncester(root, root->left, root->right);
    cout << ans->val;
    return 0;
}