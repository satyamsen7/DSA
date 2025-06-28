#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool solve(int n, vector<vector<int>>& adj, vector<int>& values) {
    if (n == 1) {
        return (values[0] > 0);
    }

    vector<int> degree(n, 0);
    for (int i = 0; i < n; ++i) {
        degree[i] = adj[i].size();
    }

    vector<bool> removed(n, false);
    int removed_count = 0;

    while (removed_count < n - 1) {
        vector<int> leaves;
        for (int i = 0; i < n; ++i) {
            if (!removed[i] && degree[i] == 1) {
                leaves.push_back(i);
            }
        }

        if (leaves.empty()) return false;

        for (int leaf : leaves) {
            if (removed[leaf]) continue;
            
            int parent = -1;
            for (int neighbor : adj[leaf]) {
                if (!removed[neighbor]) {
                    parent = neighbor;
                    break;
                }
            }

            if (parent == -1) continue;

            values[parent] -= values[leaf];
            removed[leaf] = true;
            removed_count++;

            degree[leaf] = 0;
            degree[parent]--;
        }
    }

    for (int i = 0; i < n; ++i) {
        if (!removed[i]) {
            return (values[i] > 0);
        }
    }

    return false;
}

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

        vector<int> values(n);
        for (int i = 0; i < n; ++i) {
            cin >> values[i];
        }

        if (solve(n, adj, values)) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    }
    return 0;
}