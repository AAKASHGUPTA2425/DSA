#include <iostream>
#include <vector>
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

void inorder(TreeNode *root, vector<int> &inorderArray)
{
    if (root == NULL)
        return;
    inorder(root->left, inorderArray);
    inorderArray.push_back(root->val);
    inorder(root->right, inorderArray);
    return;
}
int kthSmallest(TreeNode *root, int k)
{
    vector<int> inorderArray;
    inorder(root, inorderArray);
    int result = inorderArray[k - 1];
    return result;
}

int main()
{
    TreeNode *root = new TreeNode(5);
    root->left = new TreeNode(3);
    root->right = new TreeNode(7);
    root->left->left = new TreeNode(2);
    root->left->right = new TreeNode(4);
    root->right->left = new TreeNode(6);
    root->right->right = new TreeNode(8);

    int answer = kthSmallest(root, 3);
    cout << "the kth smallest number is" << answer;

    return 0;
}
