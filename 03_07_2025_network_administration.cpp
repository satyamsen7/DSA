#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int main() {
  int n, m;
  cin >> n >> m;

  vector<vector<int>> adj(n);
  for (int i = 0; i < m; ++i) {
    int u, v;
    cin >> u >> v;
    --u; --v;
    adj[u].push_back(v);
    adj[v].push_back(u);
  }

  int s;
  cin >> s;
  --s;

  vector<int> dist(n, -1);
  dist[s] = 0;
  queue<int> q;
  q.push(s);

  while (!q.empty()) {
    int u = q.front();
    q.pop();

    for (int v : adj[u]) {
      if (dist[v] == -1) {
        dist[v] = dist[u] + 1;
        q.push(v);
      }
    }
  }

  for (int i = 0; i < n; ++i) {
    if (i != s) {
      cout << (dist[i] == -1 ? -1 : dist[i] * 6) << " ";
    }
  }
  cout << endl;

  return 0;
}