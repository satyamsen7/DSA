#include <iostream>
#include <vector>

using namespace std;

long long sumOfMaxs(int n, vector<int>& nums) {
    long long sum = 0;
    for (int i = 0; i < n; ++i) {
        int max_val = nums[i];
        for (int j = i; j < n; ++j) {
            max_val = max(max_val, nums[j]);
            sum += max_val;
        }
    }
    return sum;
}

int main() {
    int n;
    cin >> n;
    vector<int> nums(n);
    for (int i = 0; i < n; ++i) {
        cin >> nums[i];
    }

    long long result = sumOfMaxs(n, nums);
    cout << result << endl;

    return 0;
}