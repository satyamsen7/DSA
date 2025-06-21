#include <iostream>
#include <vector>

using namespace std;

const int MOD = 1e9 + 7;

int main() {
    int n;
    cin >> n;

    vector<vector<pair<int, bool>>> adj(n);
    for (int i = 0; i < n - 1; ++i) {
        int u, v;
        string color;
        cin >> u >> v >> color;
        --u; --v;
        adj[u].push_back({v, color == "r"});
        adj[v].push_back({u, color == "r"});
    }

    vector<bool> visited(n, false);
    vector<int> componentSize;

    function<int(int)> dfs = [&](int u) {
        visited[u] = true;
        int count = 1;
        for (auto& edge : adj[u]) {
            int v = edge.first;
            bool isRed = edge.second;
            if (!visited[v] && !isRed) {
                count += dfs(v);
            }
        }
        return count;
    };

    for (int i = 0; i < n; ++i) {
        if (!visited[i]) {
            componentSize.push_back(dfs(i));
        }
    }

    long long total = (1LL * n * (n - 1) % MOD * (n - 2) % MOD);
    total = (total * 333333336) % MOD;

    long long invalid = 0;
    for (int size : componentSize) {
        invalid = (invalid + 1LL * size * (size - 1) % MOD * (size - 2) % MOD) % MOD;
        invalid = (invalid + 1LL * size * (size - 1) % MOD * (n - size) % MOD) % MOD;
    }

    invalid = (invalid * 333333336) % MOD;

    cout << (total - invalid + MOD) % MOD << endl;

    return 0;
}