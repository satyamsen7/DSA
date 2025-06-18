#include <iostream>
#include <vector>
#include <cmath>
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

    vector<int> values(n + 1);
    for (int i = 1; i <= n; ++i) {
        cin >> values[i];
    }

    long long count = 0;
    for (int i = 1; i <= n; ++i) {
        for (int j = i + 1; j <= n; ++j) {
            vector<int> parent(n + 1, 0);
            vector<bool> visited(n + 1, false);
            vector<int> q;
            q.push_back(i);
            visited[i] = true;
            int head = 0;

            while (head < q.size()) {
                int u = q[head++];
                for (int v : adj[u]) {
                    if (!visited[v]) {
                        visited[v] = true;
                        parent[v] = u;
                        q.push_back(v);
                    }
                }
            }

            vector<int> path;
            int curr = j;
            while (curr != 0) {
                path.push_back(curr);
                curr = parent[curr];
            }
            reverse(path.begin(), path.end());

            long long sum = 0;
            for (int node : path) {
                sum += values[node];
            }

            long long root = round(sqrt(sum));
            if (root * root == sum) {
                count++;
            }
        }
    }

    cout << count << endl;

    return 0;
}