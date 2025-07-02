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

    int q;
    cin >> q;

    for (int i = 0; i < q; ++i) {
        int type;
        cin >> type;

        if (type == 1) {
            int u, v;
            cin >> u >> v;

            vector<int> path;
            vector<int> parent(n + 1, 0);
            vector<bool> visited(n + 1, false);

            function<bool(int, int)> dfs = [&](int curr, int target) {
                visited[curr] = true;
                path.push_back(curr);

                if (curr == target) {
                    return true;
                }

                for (int neighbor : adj[curr]) {
                    if (!visited[neighbor]) {
                        parent[neighbor] = curr;
                        if (dfs(neighbor, target)) {
                            return true;
                        }
                    }
                }

                path.pop_back();
                return false;
            };

            dfs(u, v);
            cout << path.size() << " ";
            for (int node : path) {
                cout << node << " ";
            }
            cout << endl;
        } else {
            int u;
            cin >> u;

            vector<bool> visited(n + 1, false);
            vector<int> subtree;

            function<void(int)> dfs = [&](int curr) {
                visited[curr] = true;
                subtree.push_back(curr);

                for (int neighbor : adj[curr]) {
                    if (!visited[neighbor]) {
                        dfs(neighbor);
                    }
                }
            };

            dfs(u);
            sort(subtree.begin(), subtree.end());

            cout << subtree.size() << " ";
            for (int node : subtree) {
                cout << node << " ";
            }
            cout << endl;
        }
    }

    return 0;
}