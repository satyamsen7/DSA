#include <iostream>
#include <vector>

using namespace std;

struct Node {
    int data;
    Node *left;
    Node *right;
};

Node* createNode(int data) {
    Node* newNode = new Node();
    newNode->data = data;
    newNode->left = nullptr;
    newNode->right = nullptr;
    return newNode;
}

Node* buildFibonacciTree(int n) {
    if (n <= 0) return nullptr;
    if (n == 1) return createNode(0);
    if (n == 2) return createNode(1);

    vector<int> fib(n);
    fib[0] = 0;
    fib[1] = 1;
    for (int i = 2; i < n; ++i) {
        fib[i] = fib[i - 1] + fib[i - 2];
    }

    Node* root = createNode(fib[n - 1]);
    root->left = buildFibonacciTree(n - 1);
    root->right = buildFibonacciTree(n - 2);

    return root;
}

void inorderTraversal(Node* root) {
    if (root) {
        inorderTraversal(root->left);
        cout << root->data << " ";
        inorderTraversal(root->right);
    }
}

void deleteTree(Node* root) {
    if (root) {
        deleteTree(root->left);
        deleteTree(root->right);
        delete root;
    }
}

int main() {
    int n;
    cin >> n;

    Node* root = buildFibonacciTree(n);

    inorderTraversal(root);
    cout << endl;

    deleteTree(root);

    return 0;
}