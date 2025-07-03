#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool solve() {
  int n, k;
  cin >> n >> k;

  vector<int> a(n);
  vector<int> b(n);

  for (int i = 0; i < n; ++i) {
    cin >> a[i];
  }

  for (int i = 0; i < n; ++i) {
    cin >> b[i];
  }

  sort(a.begin(), a.end());
  sort(b.begin(), b.end(), greater<int>());

  for (int i = 0; i < n; ++i) {
    if (a[i] + b[i] < k) {
      return false;
    }
  }

  return true;
}

int main() {
  int t;
  cin >> t;

  while (t--) {
    if (solve()) {
      cout << "YES" << endl;
    } else {
      cout << "NO" << endl;
    }
  }

  return 0;
}