#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    vector<int> stops(n);
    for (int i = 0; i < n; ++i) {
        cin >> stops[i];
    }

    sort(stops.begin(), stops.end());

    int count = 1;
    int current_pos = stops[0];

    for (int i = 1; i < n; ++i) {
        if (stops[i] - current_pos > m) {
            count++;
            current_pos = stops[i];
        }
    }

    cout << count << endl;

    return 0;
}