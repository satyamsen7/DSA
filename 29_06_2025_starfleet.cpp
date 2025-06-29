#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> crew_skills(n);
    for (int i = 0; i < n; ++i) {
        cin >> crew_skills[i];
    }

    int m;
    cin >> m;

    vector<int> mission_requirements(m);
    for (int i = 0; i < m; ++i) {
        cin >> mission_requirements[i];
    }

    sort(crew_skills.begin(), crew_skills.end());
    sort(mission_requirements.begin(), mission_requirements.end());

    int crew_idx = 0;
    int mission_idx = 0;
    int completed_missions = 0;

    while (crew_idx < n && mission_idx < m) {
        if (crew_skills[crew_idx] >= mission_requirements[mission_idx]) {
            completed_missions++;
            crew_idx++;
            mission_idx++;
        } else {
            crew_idx++;
        }
    }

    cout << completed_missions << endl;

    return 0;
}