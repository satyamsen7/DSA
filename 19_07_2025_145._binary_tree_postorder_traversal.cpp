#include <iostream>
#include <vector>
#include <stack>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

vector<int> postorderTraversal(TreeNode* root) {
    vector<int> result;
    if (!root) return result;

    stack<TreeNode*> s;
    TreeNode* lastVisited = nullptr;
    TreeNode* current = root;

    while (!s.empty() || current) {
        if (current) {
            s.push(current);
            current = current->left;
        } else {
            TreeNode* peekNode = s.top();
            if (peekNode->right && lastVisited != peekNode->right) {
                current = peekNode->right;
            } else {
                result.push_back(peekNode->val);
                lastVisited = peekNode;
                s.pop();
            }
        }
    }
    return result;
}