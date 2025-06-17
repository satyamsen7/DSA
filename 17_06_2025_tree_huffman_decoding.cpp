#include <iostream>
#include <string>

using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
};

string decodeHuffman(Node* root, string s) {
    string decoded = "";
    Node* current = root;

    for (char c : s) {
        if (c == '0') {
            current = current->left;
        } else {
            current = current->right;
        }

        if (current->left == nullptr && current->right == nullptr) {
            decoded += (char)current->data;
            current = root;
        }
    }

    return decoded;
}

int main() {
  
  Node* root = new Node();
  root->data = 0;
  root->left = new Node();
  root->right = new Node();
  root->left->data = 0;
  root->right->data = 0;
  root->left->left = new Node();
  root->left->right = new Node();
  root->right->left = new Node();
  root->right->right = new Node();
  root->left->left->data = (int)'A';
  root->left->right->data = (int)'B';
  root->right->left->data = (int)'C';
  root->right->right->data = (int)'D';
  root->left->left->left = nullptr;
  root->left->left->right = nullptr;
  root->left->right->left = nullptr;
  root->left->right->right = nullptr;
  root->right->left->left = nullptr;
  root->right->left->right = nullptr;
  root->right->right->left = nullptr;
  root->right->right->right = nullptr;
  root->left->left->data = 65;
  root->left->right->data = 66;
  root->right->left->data = 67;
  root->right->right->data = 68;
  
  string encoded_string = "1001011100";
  string decoded_string = decodeHuffman(root, encoded_string);
  cout << decoded_string << endl;

  return 0;
}