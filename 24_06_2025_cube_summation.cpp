#include <iostream>
#include <vector>

using namespace std;

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n, m;
        cin >> n >> m;

        vector<vector<vector<long long>>> cube(n + 1, vector<vector<long long>>(n + 1, vector<long long>(n + 1, 0)));

        for (int i = 0; i < m; ++i) {
            string queryType;
            cin >> queryType;

            if (queryType == "UPDATE") {
                int x, y, z, w;
                cin >> x >> y >> z >> w;
                cube[x][y][z] = w;
            } else if (queryType == "QUERY") {
                int x1, y1, z1, x2, y2, z2;
                cin >> x1 >> y1 >> z1 >> x2 >> y2 >> z2;

                long long sum = 0;
                for (int x = x1; x <= x2; ++x) {
                    for (int y = y1; y <= y2; ++y) {
                        for (int z = z1; z <= z2; ++z) {
                            sum += cube[x][y][z];
                        }
                    }
                }
                cout << sum << endl;
            }
        }
    }

    return 0;
}