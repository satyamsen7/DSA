#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
  int n;
  cin >> n;

  vector<int> a(n);
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
  }

  int total_happiness = 0;
  for (int i = 0; i < (1 << n); ++i) {
    vector<int> selected_burgers;
    for (int j = 0; j < n; ++j) {
      if ((i >> j) & 1) {
        selected_burgers.push_back(a[j]);
      }
    }

    if (selected_burgers.empty()) continue;

    int current_happiness = 0;
    sort(selected_burgers.begin(), selected_burgers.end());
    
    for (int k = 0; k < selected_burgers.size(); ++k) {
        current_happiness += selected_burgers[k] * (k + 1);
    }
      
    total_happiness = max(total_happiness, current_happiness);
  }

  cout << total_happiness << endl;

  return 0;
}