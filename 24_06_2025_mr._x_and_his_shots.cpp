#include <iostream>
#include <vector>

using namespace std;

int main() {
  int n, m;
  cin >> n >> m;

  vector<pair<int, int>> contests(n);
  for (int i = 0; i < n; ++i) {
    cin >> contests[i].first >> contests[i].second;
  }

  vector<int> shots(m);
  for (int i = 0; i < m; ++i) {
    cin >> shots[i];
  }

  for (int shot : shots) {
    int count = 0;
    for (const auto& contest : contests) {
      if (shot >= contest.first && shot <= contest.second) {
        count++;
      }
    }
    cout << count << endl;
  }

  return 0;
}