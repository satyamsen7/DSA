#include <iostream>
#include <vector>

using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> b(n);
        for (int i = 0; i < n; ++i) {
            cin >> b[i];
        }

        vector<int> a;
        vector<bool> used(n + 1, false);
        for (int i = n - 1; i >= 0; --i) {
            int count = 0;
            for (int j = 1; j <= n; ++j) {
                if (!used[j]) {
                    count++;
                    if (count == b[i]) {
                        a.push_back(j);
                        used[j] = true;
                        break;
                    }
                }
            }
        }

        for (int i = n - 1; i >= 0; --i) {
            cout << a[i] << " ";
        }
        cout << endl;
    }
    return 0;
}