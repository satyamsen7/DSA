#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<pair<int, int>> findPairSums(vector<int>& nums, int target) {
    vector<pair<int, int>> result;
    sort(nums.begin(), nums.end());
    int left = 0;
    int right = nums.size() - 1;

    while (left < right) {
        int sum = nums[left] + nums[right];
        if (sum == target) {
            result.push_back({nums[left], nums[right]});
            left++;
            right--;
        } else if (sum < target) {
            left++;
        } else {
            right--;
        }
    }
    return result;
}

int main() {
    int n, target;
    cin >> n >> target;

    vector<int> nums(n);
    for (int i = 0; i < n; ++i) {
        cin >> nums[i];
    }

    vector<pair<int, int>> pairs = findPairSums(nums, target);

    for (const auto& pair : pairs) {
        cout << pair.first << " " << pair.second << endl;
    }

    return 0;
}