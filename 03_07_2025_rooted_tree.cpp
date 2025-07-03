#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> parent(n + 1);
    vector<vector<int>> children(n + 1);
    int root = 0;

    for (int i = 1; i <= n; ++i) {
        cin >> parent[i];
        if (parent[i] == 0) {
            root = i;
        } else {
            children[parent[i]].push_back(i);
        }
    }

    cout << "Root: " << root << endl;

    cout << "Children:" << endl;
    for (int i = 1; i <= n; ++i) {
        cout << i << ": ";
        for (int child : children[i]) {
            cout << child << " ";
        }
        cout << endl;
    }

    return 0;
}