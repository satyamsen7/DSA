#include <iostream>
#include <queue>
#include <vector>
#include <iomanip>

using namespace std;

int main() {
    int n;
    cin >> n;

    priority_queue<int> max_heap;
    priority_queue<int, vector<int>, greater<int>> min_heap;

    for (int i = 0; i < n; ++i) {
        int num;
        cin >> num;

        if (max_heap.empty() || num <= max_heap.top()) {
            max_heap.push(num);
        } else {
            min_heap.push(num);
        }

        if (max_heap.size() > min_heap.size() + 1) {
            min_heap.push(max_heap.top());
            max_heap.pop();
        } else if (min_heap.size() > max_heap.size()) {
            max_heap.push(min_heap.top());
            min_heap.pop();
        }

        double median;
        if (max_heap.size() == min_heap.size()) {
            median = (max_heap.top() + min_heap.top()) / 2.0;
        } else {
            median = max_heap.top();
        }

        cout << fixed << setprecision(1) << median << endl;
    }

    return 0;
}