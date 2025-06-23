#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    vector<int> pref(n, 0);
    for (int i = 0; i < n; ++i) {
        int start = (i - a[i] + 1 + n) % n;
        pref[start]++;
        int end = (i + 1) % n;
        if (start <= end) {
            pref[end]--;
        } else {
            pref[0]++;
            pref[end]--;
        }
    }

    for (int i = 1; i < n; ++i) {
        pref[i] += pref[i - 1];
    }

    int best_idx = 0;
    for (int i = 1; i < n; ++i) {
        if (pref[i] > pref[best_idx]) {
            best_idx = i;
        }
    }

    cout << best_idx + 1 << endl;

    return 0;
}