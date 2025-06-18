#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

long long solve() {
    int n;
    cin >> n;

    vector<vector<int>> adj(n + 1);
    for (int i = 0; i < n - 1; ++i) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    vector<int> values(n + 1);
    for (int i = 1; i <= n; ++i) {
        cin >> values[i];
    }

    long long max_sum = -1e18;

    for (int i = 1; i <= n; ++i) {
        for (int j = i + 1; j <= n; ++j) {
            vector<int> path;
            vector<int> parent(n + 1, 0);
            vector<bool> visited(n + 1, false);
            vector<int> q;

            q.push_back(i);
            visited[i] = true;

            int head = 0;
            while (head < q.size()) {
                int u = q[head++];
                if (u == j) break;

                for (int v : adj[u]) {
                    if (!visited[v]) {
                        visited[v] = true;
                        parent[v] = u;
                        q.push_back(v);
                    }
                }
            }

            int curr = j;
            while (curr != 0) {
                path.push_back(curr);
                curr = parent[curr];
            }
            reverse(path.begin(), path.end());

            long long current_sum = 0;
            for (int k = 0; k < path.size(); ++k) {
                current_sum += values[path[k]];
            }

            max_sum = max(max_sum, current_sum);
        }
    }

    if (max_sum == -1e18) return 0;
    return max_sum;
}

int main() {
    cout << solve() << endl;
    return 0;
}