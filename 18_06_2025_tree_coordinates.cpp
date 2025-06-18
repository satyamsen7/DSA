#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<vector<int>> adj(n + 1);
    for (int i = 0; i < n - 1; ++i) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    vector<pair<int, int>> coordinates(n + 1);
    vector<bool> visited(n + 1, false);

    function<void(int, int, int)> dfs = [&](int u, int x, int y) {
        visited[u] = true;
        coordinates[u] = {x, y};

        int dx = 1;
        for (int v : adj[u]) {
            if (!visited[v]) {
                dfs(v, x + dx, y - 1);
                dx++;
            }
        }
    };

    dfs(1, 0, 0);

    for (int i = 1; i <= n; ++i) {
        cout << coordinates[i].first << " " << coordinates[i].second << endl;
    }

    return 0;
}