#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n, q;
    cin >> n >> q;

    vector<long long> arr(n);
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }

    for (int i = 0; i < q; ++i) {
        int type;
        cin >> type;

        if (type == 1) {
            int index;
            long long value;
            cin >> index >> value;
            arr[index - 1] = value;
        } else {
            int l, r;
            cin >> l >> r;
            long long sum = 0;
            for (int j = l - 1; j < r; ++j) {
                sum += arr[j];
            }
            cout << sum << endl;
        }
    }

    return 0;
}