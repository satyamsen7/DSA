#include <iostream>
#include <vector>
#include <stack>

using namespace std;

int main() {
    int n, q;
    cin >> n >> q;

    vector<int> arr(n);
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }

    for (int i = 0; i < q; ++i) {
        int type;
        cin >> type;

        if (type == 1) {
            int l, r;
            cin >> l >> r;
            l--;
            r--;

            long long sum = 0;
            for (int j = l; j <= r; ++j) {
                sum += arr[j];
            }
            cout << sum << endl;
        } else if (type == 2) {
            int index, value;
            cin >> index >> value;
            index--;
            arr[index] = value;
        } else if (type == 3) {
            int l, r;
            cin >> l >> r;
            l--;
            r--;

            int max_val = arr[l];
            for (int j = l + 1; j <= r; ++j) {
                max_val = max(max_val, arr[j]);
            }
            cout << max_val << endl;
        }
         else if (type == 4) {
            int l, r;
            cin >> l >> r;
            l--;
            r--;
            
            int min_val = arr[l];
            for(int j=l+1; j<=r; ++j) {
                min_val = min(min_val, arr[j]);
            }
            cout << min_val << endl;

        }
    }

    return 0;
}