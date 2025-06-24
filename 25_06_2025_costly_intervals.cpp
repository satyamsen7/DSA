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

  for (int i = 0; i < q; ++i) {
    int l, r;
    cin >> l >> r;
    l--; 
    r--;

    long long max_sum = -1e18;
    for (int j = l; j <= r; ++j) {
      for (int k = j; k <= r; ++k) {
        long long current_sum = 0;
        for (int m = j; m <= k; ++m) {
          current_sum += a[m];
        }
        max_sum = max(max_sum, current_sum);
      }
    }

    cout << max_sum << endl;
  }

  return 0;
}