#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solve() {
  int n;
  cin >> n;
  string s;
  cin >> s;

  if (n % 2 != 0) {
    return -1;
  }

  int count = 0;
  for (int i = 0; i < n / 2; ++i) {
    if (s[i] != s[i + n / 2]) {
      count++;
    }
  }

  return count;
}

int main() {
  int t;
  cin >> t;
  while (t--) {
    cout << solve() << endl;
  }
  return 0;
}