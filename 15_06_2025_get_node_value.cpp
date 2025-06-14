#include <iostream>

struct Node {
  int data;
  Node* next;
};

int GetNode(Node* head, int positionFromTail) {
  if (head == nullptr) return -1;
  Node* fast = head;
  Node* slow = head;

  for (int i = 0; i < positionFromTail; ++i) {
    if (fast == nullptr) return -1;
    fast = fast->next;
  }

  if (fast == nullptr) return head->data;

  fast = fast->next;

  while (fast != nullptr) {
    fast = fast->next;
    slow = slow->next;
  }

  return slow->data;
}