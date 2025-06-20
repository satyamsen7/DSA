#include <iostream>
#include <queue>

using namespace std;

int main() {
  int n, k;
  cin >> n >> k;

  priority_queue<int, vector<int>, greater<int>> pq;
  for (int i = 0; i < n; ++i) {
    int cookie;
    cin >> cookie;
    pq.push(cookie);
  }

  int operations = 0;
  while (pq.size() > 1 && pq.top() < k) {
    int leastSweet = pq.top();
    pq.pop();
    int secondLeastSweet = pq.top();
    pq.pop();

    int newCookie = leastSweet + 2 * secondLeastSweet;
    pq.push(newCookie);
    operations++;
  }

  if (pq.top() < k) {
    cout << -1 << endl;
  } else {
    cout << operations << endl;
  }

  return 0;
}