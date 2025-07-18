#include <iostream>
#include <vector>

using namespace std;

int singleNumber(vector<int>& nums) {
    int result = 0;
    for (int num : nums) {
        result ^= num;
    }
    return result;
}

int main() {
    vector<int> nums = {2, 2, 1};
    int single = singleNumber(nums);
    cout << single << endl;

    nums = {4, 1, 2, 1, 2};
    single = singleNumber(nums);
    cout << single << endl;

    nums = {1};
    single = singleNumber(nums);
    cout << single << endl;

    return 0;
}