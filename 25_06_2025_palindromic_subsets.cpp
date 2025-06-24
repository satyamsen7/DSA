#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

int main() {
    string s;
    cin >> s;

    int n = s.length();
    long long count = 0;

    for (int i = 0; i < (1 << n); ++i) {
        string subset = "";
        for (int j = 0; j < n; ++j) {
            if ((i >> j) & 1) {
                subset += s[j];
            }
        }

        if (subset.empty()) continue;

        string reversed_subset = subset;
        reverse(reversed_subset.begin(), reversed_subset.end());

        if (subset == reversed_subset) {
            count++;
        }
    }

    cout << count << endl;

    return 0;
}