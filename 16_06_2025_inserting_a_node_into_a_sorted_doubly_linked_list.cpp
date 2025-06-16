#include <iostream>

using namespace std;

struct Node {
    int data;
    Node* next;
    Node* prev;
};

Node* sortedInsert(Node* head, int data) {
    Node* newNode = new Node;
    newNode->data = data;
    newNode->next = nullptr;
    newNode->prev = nullptr;

    if (head == nullptr) {
        return newNode;
    }

    if (data < head->data) {
        newNode->next = head;
        head->prev = newNode;
        return newNode;
    }

    Node* current = head;
    while (current->next != nullptr && current->next->data < data) {
        current = current->next;
    }

    newNode->next = current->next;
    newNode->prev = current;
    if (current->next != nullptr) {
        current->next->prev = newNode;
    }
    current->next = newNode;

    return head;
}

int main() {
    Node* head = nullptr;

    head = sortedInsert(head, 2);
    head = sortedInsert(head, 4);
    head = sortedInsert(head, 6);
    head = sortedInsert(head, 8);
    head = sortedInsert(head, 10);

    head = sortedInsert(head, 5);

    Node* current = head;
    while (current != nullptr) {
        cout << current->data << " ";
        current = current->next;
    }
    cout << endl;

    current = head;
    while(current != nullptr)
    {
        Node* temp = current;
        current = current->next;
        delete temp;
    }

    return 0;
}