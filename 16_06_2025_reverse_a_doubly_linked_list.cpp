#include <iostream>

struct Node {
    int data;
    Node* prev;
    Node* next;
};

void reverseDoublyLinkedList(Node** head) {
    if (*head == nullptr || (*head)->next == nullptr) {
        return;
    }

    Node* current = *head;
    Node* temp = nullptr;

    while (current != nullptr) {
        temp = current->prev;
        current->prev = current->next;
        current->next = temp;
        current = current->prev;
    }

    if (temp != nullptr) {
        *head = temp->prev;
    }
}