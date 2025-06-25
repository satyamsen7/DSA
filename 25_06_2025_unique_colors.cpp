#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> colors(n);
    for (int i = 0; i < n; ++i) {
        cin >> colors[i];
    }

    unordered_set<int> uniqueColors;
    for (int color : colors) {
        uniqueColors.insert(color);
    }

    cout << uniqueColors.size() << endl;

    return 0;
}