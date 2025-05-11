#include <iostream>
#include <string>
#include <queue>
#include <sstream>
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

class Codec
{
public:
void preorderserialize(TreeNode *root, string &result)
{
    if (root == NULL)
    {
        result += "null,";
        return;
    }
    result += to_string(root->val) + ',';
    preorderserialize(root->left, result);
    preorderserialize(root->right, result);
}
    string serialize(TreeNode *root)
    {
        string result;
        preorderserialize(root, result);
        return result;
    }

    TreeNode *preorderDeserialize(queue<string> &nodes)
    {
        if (nodes.empty())
            return NULL;
        string val = nodes.front();
        nodes.pop();
        if (val == "null")
            return nullptr;

        TreeNode *node = new TreeNode(stoi(val));
        node->left = preorderDeserialize(nodes);
        node->right = preorderDeserialize(nodes);

        return node;
    }
    TreeNode *Deserialize(string str)
{
    stringstream ss(str);
    string item;
    queue<string> nodes;
    while (getline(ss, item, ','))  // use ',' to match serialize
    {
        nodes.push(item);
    }
    return preorderDeserialize(nodes);
}
};
void inorder(TreeNode *root)
{
    if (!root)
        return;
    inorder(root->left);
    cout << root->val << " ";
    inorder(root->right);
}

int main()
{
    TreeNode *root = new TreeNode(4);
    root->left = new TreeNode(2);
    root->right = new TreeNode(7);
    root->right->left = new TreeNode(8);
    root->right->right = new TreeNode(9);
    root->left->left = new TreeNode(1);
    root->left->right = new TreeNode(3);
    Codec ser, deser;
    string treeString = ser.serialize(root);
    cout << "Serialized Tree: " << treeString << endl;

    TreeNode *deserializedRoot = deser.Deserialize(treeString);
    cout << "Inorder of Deserialized Tree: ";
    inorder(deserializedRoot);
    cout << endl;

    return 0;
}