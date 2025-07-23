#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

bool containsDuplicate(vector<int>& nums) {
    unordered_set<int> seen;
    for (int num : nums) {
        if (seen.count(num) > 0) {
            return true;
        }
        seen.insert(num);
    }
    return false;
}

int main() {
    vector<int> nums1 = {1, 2, 3, 1};
    cout << (containsDuplicate(nums1) ? "true" : "false") << endl;

    vector<int> nums2 = {1, 2, 3, 4};
    cout << (containsDuplicate(nums2) ? "true" : "false") << endl;

    vector<int> nums3 = {1, 1, 1, 3, 3, 4, 3, 2, 4, 2};
    cout << (containsDuplicate(nums3) ? "true" : "false") << endl;

    return 0;
}