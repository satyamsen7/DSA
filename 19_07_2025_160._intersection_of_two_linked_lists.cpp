#include <iostream>

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
    if (!headA || !headB) return nullptr;

    ListNode *a = headA;
    ListNode *b = headB;

    while (a != b) {
        a = a ? a->next : headB;
        b = b ? b->next : headA;
    }

    return a;
}

int main() {
    ListNode *headA = new ListNode(4);
    headA->next = new ListNode(1);
    ListNode *intersection = new ListNode(8);
    headA->next->next = intersection;
    intersection->next = new ListNode(4);
    intersection->next->next = new ListNode(5);

    ListNode *headB = new ListNode(5);
    headB->next = new ListNode(6);
    headB->next->next = new ListNode(1);
    headB->next->next->next = intersection;

    ListNode *intersectionNode = getIntersectionNode(headA, headB);

    if (intersectionNode) {
        std::cout << intersectionNode->val << std::endl;
    } else {
        std::cout << "No intersection" << std::endl;
    }

    ListNode *curr = headA;
    while (curr != nullptr) {
        ListNode *temp = curr;
        curr = curr->next;
        if (temp != intersection)
            delete temp;
    }
    curr = headB;
    while (curr != nullptr && curr != intersection) {
        ListNode *temp = curr;
        curr = curr->next;
        delete temp;
    }
    if(intersection){
      curr = intersection;
      while(curr != nullptr){
          ListNode* temp = curr;
          curr = curr->next;
          delete temp;
      }
    }
    
    return 0;
}