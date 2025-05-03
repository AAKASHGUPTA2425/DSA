#include <iostream>
#include <vector>
using namespace std;
class BinaryTreeNode
{
public:
    int val;
    BinaryTreeNode *left;
    BinaryTreeNode *right;
    BinaryTreeNode(int data)
    {
        val = data;
        left = NULL;
        right = NULL;
    }
};
void helper(BinaryTreeNode *root, vector<int> &result)
{
    if (root == NULL)
        return;
    helper(root->left, result);
    result.push_back(root->val);
    helper(root->right, result);
    return;
}
vector<int> Inorder_treversal(BinaryTreeNode *root)
{
    vector<int> result;
    helper(root, result);
    return result;
}
int main()
{
    BinaryTreeNode *root = new BinaryTreeNode(1);
    root->left = new BinaryTreeNode(2);
    root->right = new BinaryTreeNode(3);
    root->left->left = new BinaryTreeNode(4);
    root->left->right = new BinaryTreeNode(5);
    root->right->left = new BinaryTreeNode(6);
    root->right->right = new BinaryTreeNode(7);
    root->right->right->left = new BinaryTreeNode(8);
    root->right->right->right = new BinaryTreeNode(9);
    vector<int> result = Inorder_treversal(root);
    if (result.size() != 0)
    {
        for (int i = 0; i < result.size(); i++)
        {
            cout << result[i] << " ";
        }
    }
}