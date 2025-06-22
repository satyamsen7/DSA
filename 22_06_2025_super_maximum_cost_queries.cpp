#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
  int n, q;
  cin >> n >> q;

  vector<int> a(n);
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
  }

  sort(a.begin(), a.end());

  for (int i = 0; i < q; ++i) {
    int l, r;
    cin >> l >> r;

    long long max_cost = 0;
    for (int j = l; j <= r; ++j) {
      for (int k = j + 1; k <= r; ++k) {
        max_cost = max(max_cost, (long long)(a[j - 1] + a[k - 1]) * (k - j));
      }
    }

    cout << max_cost << endl;
  }

  return 0;
}