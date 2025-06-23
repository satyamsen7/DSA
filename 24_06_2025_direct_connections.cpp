#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
  int t;
  cin >> t;

  while (t--) {
    int n;
    cin >> n;

    vector<long long> h(n);
    for (int i = 0; i < n; ++i) {
      cin >> h[i];
    }

    long long total_cost = 0;
    for (int i = 0; i < n; ++i) {
      long long min_cost = -1;
      for (int j = 0; j < n; ++j) {
        if (i != j) {
          long long cost = abs(h[i] - h[j]) + abs(i - j);
          if (min_cost == -1 || cost < min_cost) {
            min_cost = cost;
          }
        }
      }
      total_cost += min_cost;
    }

      vector<pair<long long, int>> heights(n);
        for(int i=0; i<n; ++i){
            heights[i] = {h[i], i};
        }

    
      
      long long min_sum = 0;
      
        vector<long long> sorted_heights = h;
        sort(sorted_heights.begin(), sorted_heights.end());

         for(int i=0; i<n; ++i){
             long long min_dist = -1;
             for(int j=0; j<n; ++j){
                  if(i!=j){
                     long long dist = abs(sorted_heights[i]-sorted_heights[j]) + abs(i-j);
                     if(min_dist == -1 || dist < min_dist){
                         min_dist = dist;
                     }
                 }
             }
             min_sum+=min_dist;
         }
        

    long long ans = 0;
    for(int i=0; i<n; ++i){
        long long min_curr = -1;
        for(int j=0; j<n; ++j){
            if(i!=j){
                long long dist = abs(h[i]-h[j]) + abs(i-j);
                if(min_curr == -1 || dist < min_curr){
                    min_curr = dist;
                }
            }
        }
        ans+= min_curr;
    }

      
    

    cout << ans << endl;
  }

  return 0;
}