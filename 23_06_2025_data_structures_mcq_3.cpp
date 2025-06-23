#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
  int num_test_cases;
  cin >> num_test_cases;

  while (num_test_cases--) {
    int n;
    cin >> n;

    vector<int> arr(n);
    for (int i = 0; i < n; ++i) {
      cin >> arr[i];
    }

    int x;
    cin >> x;

    int count = 0;
    for (int i = 0; i < n; ++i) {
      if (arr[i] > x) {
        count++;
      }
    }

    cout << count << endl;
  }

  return 0;
}