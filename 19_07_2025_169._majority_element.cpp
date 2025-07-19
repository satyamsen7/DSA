#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;

int majorityElement(vector<int>& nums) {
    unordered_map<int, int> counts;
    int n = nums.size();

    for (int num : nums) {
        counts[num]++;
    }

    for (auto const& [key, val] : counts) {
        if (val > n / 2) {
            return key;
        }
    }

    return -1;
}