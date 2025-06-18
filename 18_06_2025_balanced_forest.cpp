#include <iostream>
#include <vector>
#include <numeric>

using namespace std;

long long solve() {
    int n;
    cin >> n;

    vector<long long> c(n);
    for (int i = 0; i < n; ++i) {
        cin >> c[i];
    }

    vector<vector<int>> adj(n);
    for (int i = 0; i < n - 1; ++i) {
        int u, v;
        cin >> u >> v;
        --u; --v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    long long total_sum = accumulate(c.begin(), c.end(), 0LL);
    long long min_add = -1;

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (i == j) continue;

            vector<bool> visited(n, false);
            vector<long long> subtree_sums(n, 0);

            function<void(int, int)> dfs = [&](int u, int parent) {
                visited[u] = true;
                subtree_sums[u] = c[u];

                for (int v : adj[u]) {
                    if (v != parent) {
                        dfs(v, u);
                        subtree_sums[u] += subtree_sums[v];
                    }
                }
            };
            
            dfs(i, -1);
            long long subtree1_sum = subtree_sums[i];
            
            vector<bool> visited2(n, false);
            vector<long long> subtree_sums2(n, 0);
            
            function<void(int, int)> dfs2 = [&](int u, int parent) {
                visited2[u] = true;
                subtree_sums2[u] = c[u];
                
                for (int v : adj[u]) {
                    if (v != parent && !visited[v]) {
                        dfs2(v, u);
                        subtree_sums2[u] += subtree_sums2[v];
                    }
                }
            };

            dfs2(j, -1);
            long long subtree2_sum = subtree_sums2[j];

            long long remaining_sum = total_sum - subtree1_sum - subtree2_sum;

            if (subtree1_sum == subtree2_sum) {
                long long add = abs(remaining_sum - subtree1_sum);
                if (min_add == -1 || add < min_add) {
                    min_add = add;
                }
            } else if (subtree1_sum == remaining_sum) {
                long long add = abs(subtree2_sum - subtree1_sum);
                 if (min_add == -1 || add < min_add) {
                    min_add = add;
                }

            } else if (subtree2_sum == remaining_sum) {
                long long add = abs(subtree1_sum - subtree2_sum);
                 if (min_add == -1 || add < min_add) {
                    min_add = add;
                }

            }
            
            if (2 * subtree1_sum <= total_sum) {
                if (total_sum % 2 == 0 && 2 * subtree1_sum == total_sum) {
                    if (min_add == -1 || 0 < min_add) min_add = 0;
                }
            }
            
            if (2 * subtree2_sum <= total_sum) {
                if (total_sum % 2 == 0 && 2 * subtree2_sum == total_sum) {
                     if (min_add == -1 || 0 < min_add) min_add = 0;
                }
            }
            
        }

        vector<bool> visited(n, false);
        vector<long long> subtree_sums(n, 0);

        function<void(int, int)> dfs = [&](int u, int parent) {
            visited[u] = true;
            subtree_sums[u] = c[u];

            for (int v : adj[u]) {
                if (v != parent) {
                    dfs(v, u);
                    subtree_sums[u] += subtree_sums[v];
                }
            }
        };
        
        dfs(i, -1);
        long long subtree_sum = subtree_sums[i];

        if (2 * subtree_sum <= total_sum) {
                long long add = abs(total_sum - 2 * subtree_sum);
                if (min_add == -1 || add < min_add) {
                    min_add = add;
                }
        }
    }

    return min_add;
}

int main() {
    int q;
    cin >> q;
    while (q--) {
        cout << solve() << endl;
    }
    return 0;
}