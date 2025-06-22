#include <iostream>
#include <vector>
#include <stack>

using namespace std;

int poisonousPlants(vector<int> p) {
    int n = p.size();
    vector<int> days(n, 0);
    stack<int> s;

    for (int i = 0; i < n; ++i) {
        int max_day = 0;
        while (!s.empty() && p[s.top()] >= p[i]) {
            max_day = max(max_day, days[s.top()]);
            s.pop();
        }

        if (!s.empty()) {
            days[i] = max_day + 1;
        }

        s.push(i);
    }

    int max_days = 0;
    for (int day : days) {
        max_days = max(max_days, day);
    }

    return max_days;
}

int main() {
    int n;
    cin >> n;

    vector<int> p(n);
    for (int i = 0; i < n; ++i) {
        cin >> p[i];
    }

    cout << poisonousPlants(p) << endl;

    return 0;
}