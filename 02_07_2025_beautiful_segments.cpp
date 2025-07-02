#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
  int n;
  cin >> n;

  vector<pair<int, int>> segments(n);
  for (int i = 0; i < n; ++i) {
    cin >> segments[i].first >> segments[i].second;
  }

  int count = 0;
  for (int i = 0; i < n; ++i) {
    for (int j = i; j < n; ++j) {
      int min_val = min(segments[i].first, segments[i].second);
      int max_val = max(segments[i].first, segments[i].second);
      for (int k = i + 1; k <= j; ++k) {
        min_val = min(min_val, min(segments[k].first, segments[k].second));
        max_val = max(max_val, max(segments[k].first, segments[k].second));
      }
      
      int len = max_val - min_val;
      bool beautiful = true;
      
      vector<int> values;
      for (int k = i; k <= j; ++k){
          values.push_back(segments[k].first);
          values.push_back(segments[k].second);
      }
      
      sort(values.begin(), values.end());
      values.erase(unique(values.begin(), values.end()), values.end());
      
      if(values.size() - 1 != len){
          beautiful = false;
      }
      

      if (beautiful) {
        count++;
      }
    }
  }

  cout << count << endl;

  return 0;
}