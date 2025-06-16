#include <iostream>

using namespace std;

struct Node {
    int data;
    Node* next;
};

int findMergeNode(Node* head1, Node* head2) {
    Node* current1 = head1;
    Node* current2 = head2;

    int len1 = 0;
    int len2 = 0;

    while (current1 != nullptr) {
        len1++;
        current1 = current1->next;
    }

    while (current2 != nullptr) {
        len2++;
        current2 = current2->next;
    }

    current1 = head1;
    current2 = head2;

    if (len1 > len2) {
        int diff = len1 - len2;
        for (int i = 0; i < diff; i++) {
            current1 = current1->next;
        }
    } else if (len2 > len1) {
        int diff = len2 - len1;
        for (int i = 0; i < diff; i++) {
            current2 = current2->next;
        }
    }

    while (current1 != nullptr && current2 != nullptr) {
        if (current1 == current2) {
            return current1->data;
        }
        current1 = current1->next;
        current2 = current2->next;
    }

    return -1;
}