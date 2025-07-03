#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
  int n, k;
  cin >> n >> k;

  vector<int> passengers(n);
  for (int i = 0; i < n; ++i) {
    cin >> passengers[i];
  }

  sort(passengers.begin(), passengers.end());

  int left = 0;
  int right = passengers[n - 1];
  int ans = right;

  while (left <= right) {
    int mid = left + (right - left) / 2;
    int taxis = 1;
    int current_capacity = 0;

    for (int i = 0; i < n; ++i) {
      if (passengers[i] > mid) {
        taxis = k + 1;
        break;
      }
      if (current_capacity + passengers[i] <= mid) {
        current_capacity += passengers[i];
      } else {
        taxis++;
        current_capacity = passengers[i];
      }
    }

    if (taxis <= k) {
      ans = mid;
      right = mid - 1;
    } else {
      left = mid + 1;
    }
  }

  cout << ans << endl;

  return 0;
}