#include <iostream>

struct Node {
    int data;
    Node* next;
};

void deleteNode(Node** headRef, int key) {
    Node* head = *headRef;
    Node* temp = head;
    Node* prev = nullptr;

    if (temp != nullptr && temp->data == key) {
        *headRef = temp->next;
        delete temp;
        return;
    }

    while (temp != nullptr && temp->data != key) {
        prev = temp;
        temp = temp->next;
    }

    if (temp == nullptr) {
        return;
    }

    prev->next = temp->next;
    delete temp;
}