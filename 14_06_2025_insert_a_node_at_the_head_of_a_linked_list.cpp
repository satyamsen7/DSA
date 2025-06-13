#include <iostream>

struct SinglyLinkedListNode {
    int data;
    SinglyLinkedListNode* next;
};

SinglyLinkedListNode* insertNodeAtHead(SinglyLinkedListNode* llist, int data) {
    SinglyLinkedListNode* newNode = new SinglyLinkedListNode;
    newNode->data = data;
    newNode->next = llist;
    return newNode;
}

int main() {
    SinglyLinkedListNode* head = nullptr;
    head = insertNodeAtHead(head, 3);
    head = insertNodeAtHead(head, 5);
    head = insertNodeAtHead(head, 7);

    SinglyLinkedListNode* current = head;
    while (current != nullptr) {
        std::cout << current->data << " ";
        current = current->next;
    }
    std::cout << std::endl;

    current = head;
    while (current != nullptr) {
        SinglyLinkedListNode* next = current->next;
        delete current;
        current = next;
    }
    head = nullptr;

    return 0;
}