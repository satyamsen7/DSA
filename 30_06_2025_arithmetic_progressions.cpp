#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n;
    while (cin >> n && n != 0) {
        vector<int> arr(n);
        for (int i = 0; i < n; ++i) {
            cin >> arr[i];
        }

        sort(arr.begin(), arr.end());

        int diff = -1;
        for (int i = 1; i < n; ++i) {
            if (diff == -1) {
                diff = arr[i] - arr[i - 1];
            } else if (arr[i] - arr[i - 1] != diff) {
                diff = -2;
                break;
            }
        }

        if (diff == -2) {
            cout << "Non-arithmetic sequence." << endl;
        } else {
            cout << "Arithmetic sequence, common difference " << diff << "." << endl;
        }
    }

    return 0;
}