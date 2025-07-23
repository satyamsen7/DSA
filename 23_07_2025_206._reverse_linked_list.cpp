#include <iostream>

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode* reverseList(ListNode* head) {
    ListNode *prev = nullptr;
    ListNode *curr = head;
    ListNode *next = nullptr;

    while (curr != nullptr) {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }

    return prev;
}

int main() {
    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = new ListNode(5);

    ListNode* reversedHead = reverseList(head);

    ListNode* current = reversedHead;
    while (current != nullptr) {
        std::cout << current->val << " ";
        ListNode* temp = current;
        current = current->next;
        
    }
    std::cout << std::endl;
    
    current = reversedHead;
     while (current != nullptr) {
        ListNode* temp = current;
        current = current->next;
        delete temp; 
    }

    return 0;
}