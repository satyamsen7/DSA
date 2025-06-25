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

    vector<long long> a(n);
    for (int i = 0; i < n; ++i) {
      cin >> a[i];
    }

    vector<long long> dp(n);
    dp[0] = a[0];

    for (int i = 1; i < n; ++i) {
      dp[i] = dp[i - 1] + a[i];
      for (int j = 0; j < i; ++j) {
        dp[i] = min(dp[i], (j > 0 ? dp[j - 1] : 0) + max(0LL, a[i] - a[j]));
      }
    }

    cout << dp[n - 1] << endl;
  }

  return 0;
}