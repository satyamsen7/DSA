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

vector<int> preorderTraversal(TreeNode* root) {
    vector<int> result;
    stack<TreeNode*> st;

    if (root == nullptr) {
        return result;
    }

    st.push(root);

    while (!st.empty()) {
        TreeNode* node = st.top();
        st.pop();

        result.push_back(node->val);

        if (node->right) {
            st.push(node->right);
        }

        if (node->left) {
            st.push(node->left);
        }
    }

    return result;
}