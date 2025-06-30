#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
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
        vector<int> a(n);
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
        }

        long long max_sum = 0;
        vector<int> best_subset;

        for (int i = 0; i < (1 << n); ++i) {
            vector<int> subset;
            for (int j = 0; j < n; ++j) {
                if ((i >> j) & 1) {
                    subset.push_back(j);
                }
            }

            if (subset.empty()) continue;

            bool connected = true;
            if (subset.size() > 1) {
                vector<bool> visited(n, false);
                vector<int> q;
                q.push_back(subset[0]);
                visited[subset[0]] = true;
                int head = 0;

                while (head < q.size()) {
                    int u = q[head++];
                    for (int v : adj[u]) {
                        bool v_in_subset = false;
                        for (int x : subset) {
                            if (x == v) {
                                v_in_subset = true;
                                break;
                            }
                        }
                        if (v_in_subset && !visited[v]) {
                            visited[v] = true;
                            q.push_back(v);
                        }
                    }
                }

                for (int node : subset) {
                    if (!visited[node]) {
                        connected = false;
                        break;
                    }
                }
            }

            if (connected) {
                long long current_sum = 0;
                for (int node : subset) {
                    current_sum += a[node];
                }
                if (current_sum > max_sum) {
                    max_sum = current_sum;
                    best_subset = subset;
                }
            }
        }
        cout << max_sum << endl;
    }
    return 0;
}