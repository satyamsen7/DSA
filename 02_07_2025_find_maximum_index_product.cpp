#include <iostream>
#include <vector>
#include <stack>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<long long> arr(n);
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }

    vector<int> left(n, 0);
    vector<int> right(n, 0);

    stack<int> s;
    for (int i = 0; i < n; ++i) {
        while (!s.empty() && arr[s.top()] <= arr[i]) {
            s.pop();
        }
        if (!s.empty()) {
            left[i] = s.top() + 1;
        }
        s.push(i);
    }

    while (!s.empty()) {
        s.pop();
    }

    for (int i = n - 1; i >= 0; --i) {
        while (!s.empty() && arr[s.top()] <= arr[i]) {
            s.pop();
        }
        if (!s.empty()) {
            right[i] = s.top() + 1;
        }
        s.push(i);
    }

    long long max_product = 0;
    for (int i = 0; i < n; ++i) {
        max_product = max(max_product, (long long)left[i] * right[i]);
    }

    cout << max_product << endl;

    return 0;
}