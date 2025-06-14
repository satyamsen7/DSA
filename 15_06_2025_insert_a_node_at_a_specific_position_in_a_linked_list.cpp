#include <iostream>

using namespace std;

struct Node {
    int data;
    Node* next;
};

void insertNodeAtPosition(Node** head, int data, int position) {
    Node* newNode = new Node();
    newNode->data = data;
    newNode->next = nullptr;

    if (position == 0) {
        newNode->next = *head;
        *head = newNode;
        return;
    }

    Node* current = *head;
    int count = 0;

    while (current != nullptr && count < position - 1) {
        current = current->next;
        count++;
    }

    if (current == nullptr) {
        delete newNode;
        return;
    }

    newNode->next = current->next;
    current->next = newNode;
}