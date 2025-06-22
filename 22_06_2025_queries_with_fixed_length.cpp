#include <iostream>
#include <vector>
#include <deque>

using namespace std;

vector<int> solve(vector<int>& arr, vector<int>& queries) {
    vector<int> result;
    for (int k : queries) {
        deque<int> dq;
        int max_val = INT_MIN;
        for (int i = 0; i < arr.size(); ++i) {
            while (!dq.empty() && arr[dq.back()] <= arr[i]) {
                dq.pop_back();
            }
            dq.push_back(i);

            if (i >= k - 1) {
                max_val = max(max_val, arr[dq.front()]);
                if (dq.front() == i - (k - 1)) {
                    dq.pop_front();
                }
            }
        }
        result.push_back(max_val);
    }
    return result;
}

int main() {
    vector<int> arr = {1, 2, 3, 1, 4, 5, 2, 3, 6};
    vector<int> queries = {3, 4, 5};
    vector<int> result = solve(arr, queries);
    for (int val : result) {
        cout << val << " ";
    }
    cout << endl;
    return 0;
}