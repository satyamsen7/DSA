#include <iostream>
#include <vector>
#include <numeric>

using namespace std;

int main() {
  int t;
  cin >> t;

  while (t--) {
    int n;
    cin >> n;

    vector<int> arr(n);
    for (int i = 0; i < n; ++i) {
      cin >> arr[i];
    }

    long long sum = accumulate(arr.begin(), arr.end(), 0LL);
    cout << sum << endl;
  }

  return 0;
}