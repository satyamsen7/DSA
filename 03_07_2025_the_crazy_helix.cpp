#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<vector<int>> helix(n, vector<int>(n));
    int num = 1;
    int top = 0, bottom = n - 1, left = 0, right = n - 1;

    while (num <= n * n) {
        for (int i = left; i <= right && num <= n * n; ++i) {
            helix[top][i] = num++;
        }
        top++;

        for (int i = top; i <= bottom && num <= n * n; ++i) {
            helix[i][right] = num++;
        }
        right--;

        for (int i = right; i >= left && num <= n * n; --i) {
            helix[bottom][i] = num++;
        }
        bottom--;

        for (int i = bottom; i >= top && num <= n * n; --i) {
            helix[i][left] = num++;
        }
        left++;
    }

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cout << helix[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}