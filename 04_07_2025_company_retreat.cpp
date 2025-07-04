#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> happiness(n);
    for (int i = 0; i < n; ++i) {
        cin >> happiness[i];
    }

    vector<vector<int>> adj(n);
    for (int i = 0; i < n - 1; ++i) {
        int u, v;
        cin >> u >> v;
        adj[u - 1].push_back(v - 1);
        adj[v - 1].push_back(u - 1);
    }

    vector<bool> visited(n, false);
    vector<vector<int>> dp(n, vector<int>(2, 0));

    function<void(int)> dfs = [&](int u) {
        visited[u] = true;
        dp[u][1] = happiness[u];

        for (int v : adj[u]) {
            if (!visited[v]) {
                dfs(v);
                dp[u][0] += max(dp[v][0], dp[v][1]);
                dp[u][1] += dp[v][0];
            }
        }
    };

    dfs(0);

    cout << max(dp[0][0], dp[0][1]) << endl;

    return 0;
}