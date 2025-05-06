#include <iostream>
using namespace std;
class BinaryTree
{
public:
    int val;
    BinaryTree *left;
    BinaryTree *Right;
    BinaryTree(int data)
    {
        val = data;
        left = NULL;
        Right = NULL;
    }
};
int helper(BinaryTree *root)
{
    if (root == NULL)
        return 0;
    int l = helper(root->left);
    int r = helper(root->Right);
    return 1 + max(l, r);
}
int maximumDepth(BinaryTree *root)
{
    return helper(root);
}
int main()
{
    BinaryTree *root = new BinaryTree(1);
    root->left = new BinaryTree(2);
    root->Right = new BinaryTree(3);
    root->left->left = new BinaryTree(4);
    root->left->Right = new BinaryTree(5);
    int result = maximumDepth(root);
    cout << result;
    return 0;
}