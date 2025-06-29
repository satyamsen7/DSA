#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int solve() {
  int n;
  cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
  }

  int l = 0;
  while (l < n - 1 && a[l] <= a[l + 1]) {
    ++l;
  }

  if (l == n - 1) {
    return 0;
  }

  int r = n - 1;
  while (r > 0 && a[r - 1] <= a[r]) {
    --r;
  }

  int min_val = a[r];
  int max_val = a[l];
  for (int i = r; i <= l; ++i) {
    min_val = min(min_val, a[i]);
    max_val = max(max_val, a[i]);
  }

  int left = 0;
  while (left < r && a[left] <= min_val) {
    ++left;
  }

  int right = n - 1;
  while (right > l && a[right] >= max_val) {
    --right;
  }

  return right - left + 1;
}

int main() {
  cout << solve() << endl;
  return 0;
}