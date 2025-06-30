#include <iostream>
#include <vector>
#include <queue>
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

        vector<int> values(n);
        for (int i = 0; i < n; ++i) {
            cin >> values[i];
        }

        int start_node;
        cin >> start_node;
        --start_node;

        queue<pair<int, int>> q;
        q.push({start_node, values[start_node]});

        vector<bool> visited(n, false);
        visited[start_node] = true;

        long long sum = 0;
        while (!q.empty()) {
            int u = q.front().first;
            int val = q.front().second;
            q.pop();
            sum += val;

            for (int v : adj[u]) {
                if (!visited[v]) {
                    visited[v] = true;
                    q.push({v, values[v]});
                }
            }
        }

        cout << sum << endl;
    }

    return 0;
}