#include <iostream>

template <typename T>
struct Node {
    T data;
    Node* left;
    Node* right;
    int height;

    Node(T val) : data(val), left(nullptr), right(nullptr), height(1) {}
};

template <typename T>
class AVLTree {
public:
    AVLTree() : root(nullptr) {}

    ~AVLTree() {
        destroyTree(root);
    }

    void insert(T val) {
        root = insertNode(root, val);
    }

    void remove(T val) {
        root = deleteNode(root, val);
    }

    bool search(T val) {
        return searchNode(root, val);
    }

private:
    Node<T>* root;

    int height(Node<T>* node) {
        return node ? node->height : 0;
    }

    int getBalance(Node<T>* node) {
        return node ? height(node->left) - height(node->right) : 0;
    }

    void updateHeight(Node<T>* node) {
        node->height = 1 + std::max(height(node->left), height(node->right));
    }

    Node<T>* rightRotate(Node<T>* y) {
        Node<T>* x = y->left;
        Node<T>* T2 = x->right;

        x->right = y;
        y->left = T2;

        updateHeight(y);
        updateHeight(x);

        return x;
    }

    Node<T>* leftRotate(Node<T>* x) {
        Node<T>* y = x->right;
        Node<T>* T2 = y->left;

        y->left = x;
        x->right = T2;

        updateHeight(x);
        updateHeight(y);

        return y;
    }

    Node<T>* insertNode(Node<T>* node, T val) {
        if (!node) {
            return new Node<T>(val);
        }

        if (val < node->data) {
            node->left = insertNode(node->left, val);
        } else if (val > node->data) {
            node->right = insertNode(node->right, val);
        } else {
            return node;
        }

        updateHeight(node);

        int balance = getBalance(node);

        if (balance > 1 && val < node->left->data) {
            return rightRotate(node);
        }

        if (balance < -1 && val > node->right->data) {
            return leftRotate(node);
        }

        if (balance > 1 && val > node->left->data) {
            node->left = leftRotate(node->left);
            return rightRotate(node);
        }

        if (balance < -1 && val < node->right->data) {
            node->right = rightRotate(node->right);
            return leftRotate(node);
        }

        return node;
    }

    Node<T>* minValueNode(Node<T>* node) {
        Node<T>* current = node;
        while (current->left != nullptr) {
            current = current->left;
        }
        return current;
    }

    Node<T>* deleteNode(Node<T>* node, T val) {
        if (!node) {
            return nullptr;
        }

        if (val < node->data) {
            node->left = deleteNode(node->left, val);
        } else if (val > node->data) {
            node->right = deleteNode(node->right, val);
        } else {
            if (!node->left || !node->right) {
                Node<T>* temp = node->left ? node->left : node->right;
                if (!temp) {
                    temp = node;
                    node = nullptr;
                } else {
                    *node = *temp;
                }
                delete temp;
            } else {
                Node<T>* temp = minValueNode(node->right);
                node->data = temp->data;
                node->right = deleteNode(node->right, temp->data);
            }
        }

        if (!node) {
            return nullptr;
        }

        updateHeight(node);

        int balance = getBalance(node);

        if (balance > 1 && getBalance(node->left) >= 0) {
            return rightRotate(node);
        }

        if (balance > 1 && getBalance(node->left) < 0) {
            node->left = leftRotate(node->left);
            return rightRotate(node);
        }

        if (balance < -1 && getBalance(node->right) <= 0) {
            return leftRotate(node);
        }

        if (balance < -1 && getBalance(node->right) > 0) {
            node->right = rightRotate(node->right);
            return leftRotate(node);
        }

        return node;
    }

    bool searchNode(Node<T>* node, T val) {
        if (!node) {
            return false;
        }

        if (val == node->data) {
            return true;
        } else if (val < node->data) {
            return searchNode(node->left, val);
        } else {
            return searchNode(node->right, val);
        }
    }

    void destroyTree(Node<T>* node) {
        if (node) {
            destroyTree(node->left);
            destroyTree(node->right);
            delete node;
        }
    }
};