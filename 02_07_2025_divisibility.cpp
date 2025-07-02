#include <iostream>

using namespace std;

int main() {
  int t;
  cin >> t;
  while (t--) {
    int a, b, m;
    cin >> a >> b >> m;
    if (a % m == 0) {
      cout << 0 << endl;
    } else {
      int rem = a % m;
      int diff1 = m - rem;
      int diff2 = rem;
      cout << min(diff1, diff2) << endl;
    }
  }
  return 0;
}