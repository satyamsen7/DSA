#include <iostream>
#include <vector>
#include <string>

using namespace std;

vector<string> findMissingRanges(vector<int>& nums, int lower, int upper) {
    vector<string> result;
    long long next = (long long)lower;

    for (int i = 0; i < nums.size(); ++i) {
        if ((long long)nums[i] > next) {
            if (next == (long long)nums[i] - 1) {
                result.push_back(to_string(next));
            } else {
                result.push_back(to_string(next) + "->" + to_string((long long)nums[i] - 1));
            }
        }
        next = (long long)nums[i] + 1;
    }

    if (next <= (long long)upper) {
        if (next == (long long)upper) {
            result.push_back(to_string(next));
        } else {
            result.push_back(to_string(next) + "->" + to_string((long long)upper));
        }
    }

    return result;
}