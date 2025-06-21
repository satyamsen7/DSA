#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<pair<long long, long long>> customers(n);
    for (int i = 0; i < n; ++i) {
        cin >> customers[i].first >> customers[i].second;
    }

    sort(customers.begin(), customers.end());

    long long currentTime = 0;
    long long totalWaitingTime = 0;
    priority_queue<pair<long long, long long>, vector<pair<long long, long long>>, greater<pair<long long, long long>>> pq;

    int i = 0;
    while (i < n || !pq.empty()) {
        while (i < n && customers[i].first <= currentTime) {
            pq.push({customers[i].second, customers[i].first});
            ++i;
        }

        if (pq.empty()) {
            currentTime = customers[i].first;
            continue;
        }

        long long serviceTime = pq.top().first;
        long long arrivalTime = pq.top().second;
        pq.pop();

        currentTime += serviceTime;
        totalWaitingTime += (currentTime - arrivalTime);
    }

    cout << totalWaitingTime / n << endl;

    return 0;
}