#include <iostream>

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

bool hasCycle(ListNode *head) {
    if (!head || !head->next) return false;

    ListNode *slow = head;
    ListNode *fast = head->next;

    while (fast && fast->next) {
        if (slow == fast) return true;
        slow = slow->next;
        fast = fast->next->next;
    }

    return false;
}

int main() {
    ListNode *head = new ListNode(3);
    ListNode *node2 = new ListNode(2);
    ListNode *node3 = new ListNode(0);
    ListNode *node4 = new ListNode(-4);

    head->next = node2;
    node2->next = node3;
    node3->next = node4;
    node4->next = node2;

    bool hasCycleResult = hasCycle(head);

    std::cout << (hasCycleResult ? "true" : "false") << std::endl;

    ListNode* temp = head;
    ListNode* nextNode;
    while(temp != nullptr){
        nextNode = temp->next;
        delete temp;
        temp = nextNode;
    }
    
    return 0;
}