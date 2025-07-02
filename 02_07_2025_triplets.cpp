#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    vector<int> b(n);
    for (int i = 0; i < n; ++i) {
        cin >> b[i];
    }

    vector<int> c(n);
    for (int i = 0; i < n; ++i) {
        cin >> c[i];
    }

    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    sort(c.begin(), c.end());

    long long count = 0;

    for (int j = 0; j < n; ++j) {
        long long a_count = 0;
        long long c_count = 0;

        int left_a = 0;
        int right_a = n - 1;
        while (left_a <= right_a) {
            int mid = left_a + (right_a - left_a) / 2;
            if (a[mid] < b[j]) {
                a_count = mid + 1;
                left_a = mid + 1;
            } else {
                right_a = mid - 1;
            }
        }

        int left_c = 0;
        int right_c = n - 1;
        while (left_c <= right_c) {
            int mid = left_c + (right_c - left_c) / 2;
            if (c[mid] > b[j]) {
                c_count = n - mid;
                right_c = mid - 1;
            } else {
                left_c = mid + 1;
            }
        }

        count += a_count * c_count;
    }

    cout << count << endl;

    return 0;
}