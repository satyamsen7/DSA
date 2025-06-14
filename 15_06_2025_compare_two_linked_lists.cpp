#include <iostream>

struct Node {
    int data;
    Node* next;
};

bool compareLinkedLists(Node* head1, Node* head2) {
    while (head1 != nullptr && head2 != nullptr) {
        if (head1->data != head2->data) {
            return false;
        }
        head1 = head1->next;
        head2 = head2->next;
    }

    return (head1 == nullptr && head2 == nullptr);
}