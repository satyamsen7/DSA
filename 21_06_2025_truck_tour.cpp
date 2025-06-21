#include <iostream>
#include <vector>

using namespace std;

int truckTour(vector<vector<int>> &petrolpumps) {
    int n = petrolpumps.size();
    int start = 0;
    int balance = 0;
    int deficit = 0;

    for (int i = 0; i < n; ++i) {
        balance += petrolpumps[i][0] - petrolpumps[i][1];

        if (balance < 0) {
            deficit += balance;
            balance = 0;
            start = i + 1;
        }
    }

    if (balance + deficit >= 0) {
        return start;
    } else {
        return -1;
    }
}

int main() {
    int n;
    cin >> n;

    vector<vector<int>> petrolpumps(n, vector<int>(2));
    for (int i = 0; i < n; ++i) {
        cin >> petrolpumps[i][0] >> petrolpumps[i][1];
    }

    cout << truckTour(petrolpumps) << endl;

    return 0;
}