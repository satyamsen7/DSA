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

    vector<int> arr(n);
    for (int i = 0; i < n; ++i) {
      cin >> arr[i];
    }

    vector<int> sorted_arr = arr;
    sort(sorted_arr.begin(), sorted_arr.end());

    vector<int> result(n);
    for (int i = 0; i < n; ++i) {
      auto it = lower_bound(sorted_arr.begin(), sorted_arr.end(), arr[i]);
      result[i] = distance(sorted_arr.begin(), it) + 1;
      sorted_arr.erase(it);
    }

    for (int i = 0; i < n; ++i) {
      cout << result[i] << (i == n - 1 ? "" : " ");
    }
    cout << endl;
  }

  return 0;
}