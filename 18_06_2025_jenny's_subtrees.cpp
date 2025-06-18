#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
  int n, k;
  cin >> n >> k;

  vector<int> parent(n + 1);
  for (int i = 2; i <= n; ++i) {
    cin >> parent[i];
  }

  vector<vector<int>> adj(n + 1);
  for (int i = 2; i <= n; ++i) {
    adj[parent[i]].push_back(i);
  }

  long long count = 0;
  for (int i = 1; i <= n; ++i) {
    
    function<int(int)> subtree_size = [&](int u) {
      int size = 1;
      for (int v : adj[u]) {
        size += subtree_size(v);
      }
      return size;
    };

    if (subtree_size(i) >= k) {
      count++;
    }
  }

  cout << count << endl;

  return 0;
}