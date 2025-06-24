#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
  int n, q;
  cin >> n >> q;

  vector<int> a(n + 1);
  for (int i = 1; i <= n; ++i) {
    cin >> a[i];
  }

  vector<vector<int>> adj(n + 1);
  for (int i = 0; i < n - 1; ++i) {
    int u, v;
    cin >> u >> v;
    adj[u].push_back(v);
    adj[v].push_back(u);
  }

  for (int i = 0; i < q; ++i) {
    int u, v, x;
    cin >> u >> v >> x;

    vector<int> path;
    vector<int> parent(n + 1, 0);
    vector<bool> visited(n + 1, false);

    function<bool(int, int)> find_path = [&](int curr, int target) {
      visited[curr] = true;
      if (curr == target) {
        return true;
      }

      for (int neighbor : adj[curr]) {
        if (!visited[neighbor]) {
          parent[neighbor] = curr;
          if (find_path(neighbor, target)) {
            return true;
          }
        }
      }
      return false;
    };

    find_path(u, v);

    int curr = v;
    while (curr != 0) {
      path.push_back(curr);
      curr = parent[curr];
    }
    reverse(path.begin(), path.end());

    int count = 0;
    for (int node : path) {
      if (a[node] >= x) {
        count++;
      }
    }
    cout << count << endl;
  }

  return 0;
}