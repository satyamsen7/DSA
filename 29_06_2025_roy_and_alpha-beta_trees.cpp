#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int solve() {
    int n, m;
    cin >> n >> m;

    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    sort(a.begin(), a.end());

    int ans = 0;
    for (int i = 0; i < m; ++i) {
        int x;
        cin >> x;

        int l = 0, r = n - 1;
        int best_idx = -1;

        while (l <= r) {
            int mid = l + (r - l) / 2;
            if (a[mid] <= x) {
                best_idx = mid;
                l = mid + 1;
            } else {
                r = mid - 1;
            }
        }

        if (best_idx != -1) {
            ans++;
        }
    }

    return ans;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        cout << solve() << endl;
    }
    return 0;
}