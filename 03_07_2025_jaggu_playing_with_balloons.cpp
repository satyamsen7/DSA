#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
  int t;
  cin >> t;

  while (t--) {
    int n, k;
    cin >> n >> k;

    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
      cin >> a[i];
    }

    sort(a.begin(), a.end());

    long long sum = 0;
    for (int i = 0; i < n - k; ++i) {
      sum += a[i];
    }

    cout << sum << endl;
  }

  return 0;
}