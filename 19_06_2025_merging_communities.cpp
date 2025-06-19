#include <iostream>
#include <vector>

using namespace std;

class DisjointSet {
private:
    vector<int> parent;
    vector<int> size;

public:
    DisjointSet(int n) : parent(n), size(n, 1) {
        for (int i = 0; i < n; ++i) {
            parent[i] = i;
        }
    }

    int find(int x) {
        if (x != parent[x]) {
            parent[x] = find(parent[x]);
        }
        return parent[x];
    }

    void unite(int x, int y) {
        int rootX = find(x);
        int rootY = find(y);
        if (rootX != rootY) {
            if (size[rootX] < size[rootY]) {
                swap(rootX, rootY);
            }
            parent[rootY] = rootX;
            size[rootX] += size[rootY];
        }
    }

    int getSize(int x) {
        return size[find(x)];
    }
};

int main() {
    int n, q;
    cin >> n >> q;

    DisjointSet ds(n);

    for (int i = 0; i < q; ++i) {
        char type;
        cin >> type;

        if (type == 'Q') {
            int person;
            cin >> person;
            cout << ds.getSize(person - 1) << endl;
        } else {
            int person1, person2;
            cin >> person1 >> person2;
            ds.unite(person1 - 1, person2 - 1);
        }
    }

    return 0;
}