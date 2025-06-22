#include <iostream>
#include <vector>

using namespace std;

int twoStacks(int x, vector<int>& a, vector<int>& b) {
    int count = 0;
    int sum = 0;
    int i = 0;
    int j = 0;

    while (i < a.size() && sum + a[i] <= x) {
        sum += a[i];
        i++;
    }
    count = i;

    while (j < b.size() && i >= 0) {
        sum += b[j];
        j++;

        while (sum > x && i > 0) {
            i--;
            sum -= a[i];
        }

        if (sum <= x && i + j > count) {
            count = i + j;
        }
    }

    return count;
}

int main() {
    int g;
    cin >> g;

    for (int i = 0; i < g; i++) {
        int n, m, x;
        cin >> n >> m >> x;

        vector<int> a(n);
        for (int j = 0; j < n; j++) {
            cin >> a[j];
        }

        vector<int> b(m);
        for (int j = 0; j < m; j++) {
            cin >> b[j];
        }

        cout << twoStacks(x, a, b) << endl;
    }

    return 0;
}