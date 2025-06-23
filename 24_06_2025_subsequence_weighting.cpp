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

    vector<int> w(n);
    for (int i = 0; i < n; ++i) {
      cin >> w[i];
    }

    vector<long long> dp(n, 0);
    long long max_weight = 0;

    for (int i = 0; i < n; ++i) {
      dp[i] = w[i];
      for (int j = 0; j < i; ++j) {
        if (a[i] >= a[j]) {
          dp[i] = max(dp[i], dp[j] + w[i]);
        }
      }
      max_weight = max(max_weight, dp[i]);
    }

    cout << max_weight << endl;
  }

  return 0;
}