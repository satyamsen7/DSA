#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
  int t;
  cin >> t;

  while (t--) {
    int n;
    cin >> n;

    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
      cin >> a[i];
    }

    long long max_prod = -1e18;

    for (int i = 0; i < (1 << n); ++i) {
      vector<int> sub1, sub2;
      for (int j = 0; j < n; ++j) {
        if ((i >> j) & 1) {
          sub1.push_back(a[j]);
        } else {
          sub2.push_back(a[j]);
        }
      }

      if (sub1.empty() || sub2.empty()) continue;

      long long sum1 = 0, sum2 = 0;
      for (int x : sub1) sum1 += x;
      for (int x : sub2) sum2 += x;

      max_prod = max(max_prod, sum1 * sum2);
    }

    cout << max_prod << endl;
  }

  return 0;
}