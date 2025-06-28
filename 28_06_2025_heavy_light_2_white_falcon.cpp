#include <iostream>
#include <vector>

using namespace std;

const int MAXN = 1e5 + 5;

int n, q;
vector<int> adj[MAXN];
int subtree_size[MAXN];
int parent[MAXN];
int depth[MAXN];
int heavy_child[MAXN];
int head[MAXN];
int pos[MAXN];
int timer;
int a[MAXN];
long long tree[4 * MAXN];
long long lazy[4 * MAXN];

void dfs_size(int u, int p, int d) {
    subtree_size[u] = 1;
    parent[u] = p;
    depth[u] = d;
    heavy_child[u] = -1;
    for (int v : adj[u]) {
        if (v != p) {
            dfs_size(v, u, d + 1);
            subtree_size[u] += subtree_size[v];
            if (heavy_child[u] == -1 || subtree_size[v] > subtree_size[heavy_child[u]]) {
                heavy_child[u] = v;
            }
        }
    }
}

void decompose(int u, int h) {
    head[u] = h;
    pos[u] = timer++;
    if (heavy_child[u] != -1) {
        decompose(heavy_child[u], h);
    }
    for (int v : adj[u]) {
        if (v != parent[u] && v != heavy_child[u]) {
            decompose(v, v);
        }
    }
}

void build(int v, int tl, int tr) {
    if (tl == tr) {
        tree[v] = a[tl];
    } else {
        int tm = (tl + tr) / 2;
        build(v * 2, tl, tm);
        build(v * 2 + 1, tm + 1, tr);
        tree[v] = tree[v * 2] + tree[v * 2 + 1];
    }
}

void push(int v, int tl, int tr) {
    if (lazy[v] != 0) {
        tree[v] += lazy[v] * (tr - tl + 1);
        if (tl != tr) {
            lazy[v * 2] += lazy[v];
            lazy[v * 2 + 1] += lazy[v];
        }
        lazy[v] = 0;
    }
}

void update(int v, int tl, int tr, int l, int r, int add) {
    push(v, tl, tr);
    if (l > r) {
        return;
    }
    if (l == tl && r == tr) {
        lazy[v] += add;
        push(v, tl, tr);
    } else {
        int tm = (tl + tr) / 2;
        update(v * 2, tl, tm, l, min(r, tm), add);
        update(v * 2 + 1, tm + 1, tr, max(l, tm + 1), r, add);
        tree[v] = tree[v * 2] + tree[v * 2 + 1];
    }
}

long long query(int v, int tl, int tr, int l, int r) {
    push(v, tl, tr);
    if (l > r) {
        return 0;
    }
    if (l == tl && r == tr) {
        return tree[v];
    } else {
        int tm = (tl + tr) / 2;
        return query(v * 2, tl, tm, l, min(r, tm)) +
               query(v * 2 + 1, tm + 1, tr, max(l, tm + 1), r);
    }
}

void update_path(int u, int v, int add) {
    while (head[u] != head[v]) {
        if (depth[head[u]] < depth[head[v]]) {
            swap(u, v);
        }
        update(1, 0, n - 1, pos[head[u]], pos[u], add);
        u = parent[head[u]];
    }
    if (depth[u] < depth[v]) {
        swap(u, v);
    }
    update(1, 0, n - 1, pos[v], pos[u], add);
}

long long query_path(int u, int v) {
    long long res = 0;
    while (head[u] != head[v]) {
        if (depth[head[u]] < depth[head[v]]) {
            swap(u, v);
        }
        res += query(1, 0, n - 1, pos[head[u]], pos[u]);
        u = parent[head[u]];
    }
    if (depth[u] < depth[v]) {
        swap(u, v);
    }
    res += query(1, 0, n - 1, pos[v], pos[u]);
    return res;
}

void update_subtree(int u, int add) {
    update(1, 0, n - 1, pos[u], pos[u] + subtree_size[u] - 1, add);
}

long long query_subtree(int u) {
    return query(1, 0, n - 1, pos[u], pos[u] + subtree_size[u] - 1);
}

int main() {
    cin >> n >> q;
    for (int i = 0; i < n - 1; i++) {
        int u, v;
        cin >> u >> v;
        u--;
        v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    dfs_size(0, -1, 0);
    decompose(0, 0);

    for (int i = 0; i < n; i++) {
        cin >> a[pos[i]];
    }

    build(1, 0, n - 1);

    for (int i = 0; i < q; i++) {
        int type, u, v, x;
        cin >> type;
        if (type == 1) {
            cin >> u >> x;
            u--;
            update_subtree(u, x);
        } else {
            cin >> u;
            u--;
            cout << query_subtree(u) << endl;
        }
    }

    return 0;
}