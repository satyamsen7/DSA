#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> nums;
    for (int i = 0; i < n; ++i) {
        int x;
        cin >> x;
        nums.push_back(x);

        sort(nums.begin(), nums.end());

        if (nums.size() % 2 == 0) {
            cout << (nums[nums.size() / 2 - 1] + nums[nums.size() / 2]) / 2 << " ";
        } else {
            cout << nums[nums.size() / 2] << " ";
        }
    }

    cout << endl;

    return 0;
}