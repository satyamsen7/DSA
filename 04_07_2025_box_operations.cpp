#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n, q;
    cin >> n >> q;

    vector<int> boxes(n + 1, 0);

    for (int i = 0; i < q; ++i) {
        int type, l, r, v;
        cin >> type;

        if (type == 1) {
            cin >> l >> r >> v;
            for (int j = l; j <= r; ++j) {
                boxes[j] += v;
            }
        } else if (type == 2) {
            cin >> l >> r >> v;
            for (int j = l; j <= r; ++j) {
                boxes[j] = v;
            }
        } else {
            cin >> l >> r;
            long long sum = 0;
            for (int j = l; j <= r; ++j) {
                sum += boxes[j];
            }
            cout << sum << endl;
        }
    }

    return 0;
}