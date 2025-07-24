#include <iostream>
#include <algorithm>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

int countNodes(TreeNode* root) {
    if (!root) return 0;

    int leftHeight = 0;
    TreeNode* leftNode = root;
    while (leftNode) {
        leftHeight++;
        leftNode = leftNode->left;
    }

    int rightHeight = 0;
    TreeNode* rightNode = root;
    while (rightNode) {
        rightHeight++;
        rightNode = rightNode->right;
    }

    if (leftHeight == rightHeight) {
        return (1 << leftHeight) - 1;
    }

    return 1 + countNodes(root->left) + countNodes(root->right);
}

int main() {
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    root->right->left = new TreeNode(6);

    int count = countNodes(root);
    cout << count << endl;

    return 0;
}