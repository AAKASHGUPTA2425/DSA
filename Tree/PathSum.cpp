#include <iostream>
#include <vector>
using namespace std;

class TreeNode {
public:
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int data) {
        val = data;
        left = NULL;
        right = NULL;
    }
};

// Helper function that accumulates path sums at leaves
void helper(TreeNode* root, vector<int>& path, int currentSum) {
    if (!root)
        return;

    currentSum += root->val;

    // If leaf node, record the currentSum in path
    if (!root->left && !root->right) {
        path.push_back(currentSum);
        return;
    }

    // Continue DFS traversal
    helper(root->left, path, currentSum);
    helper(root->right, path, currentSum);
}

bool hasPathSum(TreeNode* root, int targetSum) {
    vector<int> pathSums;
    helper(root, pathSums, 0);

    for (int sum : pathSums) {
        if (sum == targetSum)
            return true;
    }
    return false;
}

int main() {
    TreeNode* root = new TreeNode(5);
    root->left = new TreeNode(4);
    root->right = new TreeNode(8);
    root->left->left = new TreeNode(11);
    root->left->left->left = new TreeNode(7);
    root->left->left->right = new TreeNode(2);
    root->right->left = new TreeNode(13);
    root->right->right = new TreeNode(4);
    root->right->right->right = new TreeNode(1);

    bool result = hasPathSum(root, 22);
    cout << (result ? "Path with sum 22 exists.\n" : "No path with sum 22.\n");

    return 0;
}
