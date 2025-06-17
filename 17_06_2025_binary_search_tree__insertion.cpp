#include <iostream>

using namespace std;

struct Node {
  int data;
  Node *left;
  Node *right;

  Node(int val) : data(val), left(nullptr), right(nullptr) {}
};

Node *insert(Node *root, int data) {
  if (root == nullptr) {
    return new Node(data);
  }

  if (data < root->data) {
    root->left = insert(root->left, data);
  } else if (data > root->data) {
    root->right = insert(root->right, data);
  }

  return root;
}

int main() {
  Node *root = nullptr;
  int n, data;

  cin >> n;

  for (int i = 0; i < n; ++i) {
    cin >> data;
    root = insert(root, data);
  }
  return 0;
}