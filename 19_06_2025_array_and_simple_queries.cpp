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
    int type, l, r, k;
    cin >> type;

    if (type == 1) {
      cin >> l >> r >> k;
      l--; 
      r--;
      int count = 0;
      for (int j = l; j <= r; ++j) {
        if (arr[j] % k == 0) {
          count++;
        }
      }
      cout << count << endl;
    } else {
      cin >> k >> l;
      l--;
      arr[l] = k;
    }
  }

  return 0;
}