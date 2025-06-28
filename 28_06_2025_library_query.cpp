#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n, q;
    cin >> n >> q;

    vector<pair<string, int>> books(n);
    for (int i = 0; i < n; ++i) {
        cin >> books[i].first >> books[i].second;
    }

    for (int i = 0; i < q; ++i) {
        string queryType;
        cin >> queryType;

        if (queryType == "TITLE") {
            string title;
            cin >> title;
            int count = 0;
            for (int j = 0; j < n; ++j) {
                if (books[j].first == title) {
                    count++;
                }
            }
            cout << count << endl;
        } else if (queryType == "YEAR") {
            int year;
            cin >> year;
            int count = 0;
            for (int j = 0; j < n; ++j) {
                if (books[j].second == year) {
                    count++;
                }
            }
            cout << count << endl;
        } else if (queryType == "RANGE") {
            int startYear, endYear;
            cin >> startYear >> endYear;
            int count = 0;
            for (int j = 0; j < n; ++j) {
                if (books[j].second >= startYear && books[j].second <= endYear) {
                    count++;
                }
            }
            cout << count << endl;
        }
    }

    return 0;
}