#include <iostream>
#include <vector>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

bool isPalindrome(ListNode* head) {
    vector<int> values;
    ListNode* current = head;
    while (current != nullptr) {
        values.push_back(current->val);
        current = current->next;
    }

    int left = 0;
    int right = values.size() - 1;

    while (left < right) {
        if (values[left] != values[right]) {
            return false;
        }
        left++;
        right--;
    }

    return true;
}