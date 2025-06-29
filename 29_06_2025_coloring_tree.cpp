#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
  int n;
  cin >> n;

  vector<vector<int>> adj(n);
  for (int i = 0; i < n - 1; ++i) {
    int u, v;
    cin >> u >> v;
    --u; --v;
    adj[u].push_back(v);
    adj[v].push_back(u);
  }

  vector<int> colors(n);
  for (int i = 0; i < n; ++i) {
    cin >> colors[i];
  }

  int q;
  cin >> q;

  for (int i = 0; i < q; ++i) {
    int type;
    cin >> type;

    if (type == 1) {
      int u, new_color;
      cin >> u >> new_color;
      --u;
      colors[u] = new_color;
    } else {
      int u, v;
      cin >> u >> v;
      --u; --v;

      vector<int> path_u, path_v;
      vector<int> parent(n, -1);
      vector<bool> visited(n, false);

      vector<int> q;
      q.push_back(u);
      visited[u] = true;

      int head = 0;
      while (head < q.size()) {
        int curr = q[head++];

        if (curr == v) break;

        for (int neighbor : adj[curr]) {
          if (!visited[neighbor]) {
            visited[neighbor] = true;
            parent[neighbor] = curr;
            q.push_back(neighbor);
          }
        }
      }

      int curr = v;
      while (curr != -1) {
        path_v.push_back(curr);
        curr = parent[curr];
      }
      reverse(path_v.begin(), path_v.end());

      fill(parent.begin(), parent.end(), -1);
      fill(visited.begin(), visited.end(), false);

      q.clear();
      q.push_back(u);
      visited[u] = true;

      head = 0;
      while (head < q.size()) {
        int curr = q[head++];

        for (int neighbor : adj[curr]) {
          if (!visited[neighbor]) {
            visited[neighbor] = true;
            parent[neighbor] = curr;
            q.push_back(neighbor);
          }
        }
      }

      curr = u;
      while (curr != -1) {
        path_u.push_back(curr);
        curr = parent[curr];
      }
      reverse(path_u.begin(), path_u.end());

      int lca_index = 0;
      while (lca_index < min(path_u.size(), path_v.size()) && path_u[lca_index] == path_v[lca_index]) {
        ++lca_index;
      }
      --lca_index;

      vector<int> path;
      for (int j = lca_index; j >= 0; --j) {
        path.push_back(path_u[j]);
      }
      for (int j = lca_index + 1; j < path_v.size(); ++j) {
        path.push_back(path_v[j]);
      }

      int distinct_colors = 0;
      vector<bool> seen(n + 1, false);
      for (int node : path) {
        if (!seen[colors[node]]) {
          distinct_colors++;
          seen[colors[node]] = true;
        }
      }
      cout << distinct_colors << endl;
    }
  }

  return 0;
}