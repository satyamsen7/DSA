#include <iostream>

using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
};

Node* createNode(int data) {
    Node* newNode = new Node();
    newNode->data = data;
    newNode->left = newNode->right = nullptr;
    return newNode;
}

Node* lowestCommonAncestor(Node* root, Node* p, Node* q) {
    if (root == nullptr) {
        return nullptr;
    }

    if (root->data > p->data && root->data > q->data) {
        return lowestCommonAncestor(root->left, p, q);
    } else if (root->data < p->data && root->data < q->data) {
        return lowestCommonAncestor(root->right, p, q);
    } else {
        return root;
    }
}

int main() {
    Node* root = createNode(20);
    root->left = createNode(8);
    root->right = createNode(22);
    root->left->left = createNode(4);
    root->left->right = createNode(12);
    root->left->right->left = createNode(10);
    root->left->right->right = createNode(14);

    Node* node1 = root->left->left;
    Node* node2 = root->left->right->right;

    Node* lca = lowestCommonAncestor(root, node1, node2);

    if (lca != nullptr) {
        cout << lca->data << endl;
    } else {
        cout << "LCA not found" << endl;
    }

    return 0;
}