#include <iostream>
#include <vector>

using namespace std;

int main() {
  int n, q;
  cin >> n >> q;

  vector<int> arr(n);
  for (int i = 0; i < n; ++i) {
    cin >> arr[i];
  }

  for (int i = 0; i < q; ++i) {
    int type;
    cin >> type;

    if (type == 1) {
      int l, r;
      cin >> l >> r;
      long long sum = 0;
      for (int j = l - 1; j < r; ++j) {
        sum += arr[j];
      }
      cout << sum << endl;
    } else if (type == 2) {
      int index, val;
      cin >> index >> val;
      arr[index - 1] = val;
    }
  }

  return 0;
}