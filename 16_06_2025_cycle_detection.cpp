#include <iostream>
#include <vector>

using namespace std;

bool hasCycle(int n, const vector<vector<int>>& adj) {
    vector<int> visited(n, 0);

    function<bool(int)> dfs = [&](int u) {
        visited[u] = 1;

        for (int v : adj[u]) {
            if (visited[v] == 1) {
                return true;
            }
            if (visited[v] == 0 && dfs(v)) {
                return true;
            }
        }

        visited[u] = 2;
        return false;
    };

    for (int i = 0; i < n; ++i) {
        if (visited[i] == 0 && dfs(i)) {
            return true;
        }
    }

    return false;
}

int main() {
    int n, m;
    cin >> n >> m;

    vector<vector<int>> adj(n);
    for (int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
    }

    if (hasCycle(n, adj)) {
        cout << "Cycle detected" << endl;
    } else {
        cout << "No cycle detected" << endl;
    }

    return 0;
}