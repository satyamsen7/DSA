#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int downToZero(int n) {
    if (n == 0) return 0;
    vector<int> dist(n + 1, -1);
    queue<int> q;
    q.push(n);
    dist[n] = 0;

    while (!q.empty()) {
        int u = q.front();
        q.pop();

        if (u == 0) return dist[u];

        if (u - 1 >= 0 && dist[u - 1] == -1) {
            dist[u - 1] = dist[u] + 1;
            q.push(u - 1);
        }

        for (int i = 2; i * i <= u; ++i) {
            if (u % i == 0) {
                int v = u / i;
                if (v <= n && dist[v] == -1) {
                    dist[v] = dist[u] + 1;
                    q.push(v);
                }
            }
        }
    }
    return -1;
}

int main() {
    int q;
    cin >> q;

    for (int i = 0; i < q; ++i) {
        int n;
        cin >> n;
        cout << downToZero(n) << endl;
    }

    return 0;
}