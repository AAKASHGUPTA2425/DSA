#include <iostream>
#include <vector>
#include <queue>
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

vector<vector<int>> orderTraversal(TreeNode *root)
{
    if (root == NULL)
        return {};
    queue<TreeNode *> q;
    vector<vector<int>> result;
    q.push(root);
    while (!q.empty())
    {
        vector<int> level;
        int size = q.size();
        for (int i = 0; i < size; i++)
        {
            TreeNode *node = q.front();
            q.pop();
            level.push_back(node->val);
            if (node->left)
                q.push(node->left);
            if (node->right)
                q.push(node->right);
        }
        result.push_back(level);
    }
    return result;
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
    vector<vector<int>> result = orderTraversal(root);
    if (result.size() != 0)
    {
        for (int i = 0; i < result.size(); i++)
        {
            for (int j = 0; j < result[i].size(); j++)
            {
                cout << result[i][j]<<" ";
            }
            cout << endl;
        }
    }
    return 0;
}