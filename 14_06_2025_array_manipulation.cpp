#include <iostream>
#include <vector>

using namespace std;

long arrayManipulation(int n, vector<vector<int>>& queries) {
    vector<long> arr(n, 0);
    for (auto& query : queries) {
        int a = query[0] - 1;
        int b = query[1] - 1;
        int k = query[2];
        arr[a] += k;
        if (b + 1 < n) {
            arr[b + 1] -= k;
        }
    }
    long max_val = 0;
    long current_val = 0;
    for (int i = 0; i < n; ++i) {
        current_val += arr[i];
        max_val = max(max_val, current_val);
    }
    return max_val;
}

int main() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> queries(m, vector<int>(3));
    for (int i = 0; i < m; ++i) {
        cin >> queries[i][0] >> queries[i][1] >> queries[i][2];
    }
    cout << arrayManipulation(n, queries) << endl;
    return 0;
}