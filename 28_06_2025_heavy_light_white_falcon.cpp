#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
  int n, q;
  cin >> n >> q;

  vector<vector<int>> adj(n + 1);
  for (int i = 0; i < n - 1; ++i) {
    int u, v;
    cin >> u >> v;
    adj[u].push_back(v);
    adj[v].push_back(u);
  }

  vector<int> color(n + 1);
  for (int i = 1; i <= n; ++i) {
    cin >> color[i];
  }

  for (int i = 0; i < q; ++i) {
    int u, v;
    cin >> u >> v;

    vector<int> path;
    vector<int> parent(n + 1, 0);
    vector<bool> visited(n + 1, false);

    function<bool(int, int)> dfs = [&](int curr, int target) {
      visited[curr] = true;
      path.push_back(curr);

      if (curr == target) {
        return true;
      }

      for (int neighbor : adj[curr]) {
        if (!visited[neighbor]) {
          parent[neighbor] = curr;
          if (dfs(neighbor, target)) {
            return true;
          }
        }
      }

      path.pop_back();
      return false;
    };

    dfs(u, v);

    int count = 0;
    for (int node : path) {
      if (color[node] == 1) {
        count++;
      }
    }
    
    cout << count << endl;
  }

  return 0;
}