#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

bool containsNearbyDuplicate(vector<int>& nums, int k) {
    unordered_map<int, int> seen;
    for (int i = 0; i < nums.size(); ++i) {
        if (seen.count(nums[i])) {
            if (i - seen[nums[i]] <= k) {
                return true;
            }
        }
        seen[nums[i]] = i;
    }
    return false;
}

int main() {
    vector<int> nums1 = {1, 2, 3, 1};
    int k1 = 3;
    cout << (containsNearbyDuplicate(nums1, k1) ? "true" : "false") << endl;

    vector<int> nums2 = {1, 0, 1, 1};
    int k2 = 1;
    cout << (containsNearbyDuplicate(nums2, k2) ? "true" : "false") << endl;

    vector<int> nums3 = {1, 2, 3, 1, 2, 3};
    int k3 = 2;
    cout << (containsNearbyDuplicate(nums3, k3) ? "true" : "false") << endl;

    return 0;
}