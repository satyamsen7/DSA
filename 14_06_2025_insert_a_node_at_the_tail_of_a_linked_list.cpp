#include <iostream>

using namespace std;

class SinglyLinkedListNode {
public:
    int data;
    SinglyLinkedListNode *next;

    SinglyLinkedListNode(int data) {
        this->data = data;
        this->next = nullptr;
    }
};

SinglyLinkedListNode* insertNodeAtTail(SinglyLinkedListNode *head, int data) {
    SinglyLinkedListNode* newNode = new SinglyLinkedListNode(data);

    if (head == nullptr) {
        return newNode;
    }

    SinglyLinkedListNode* current = head;
    while (current->next != nullptr) {
        current = current->next;
    }

    current->next = newNode;
    return head;
}