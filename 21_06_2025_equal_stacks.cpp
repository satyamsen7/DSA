#include <iostream>
#include <vector>
#include <numeric>

using namespace std;

int equalStacks(vector<int> h1, vector<int> h2, vector<int> h3) {
    int sum1 = accumulate(h1.begin(), h1.end(), 0);
    int sum2 = accumulate(h2.begin(), h2.end(), 0);
    int sum3 = accumulate(h3.begin(), h3.end(), 0);

    int i = 0, j = 0, k = 0;

    while (true) {
        if (sum1 == sum2 && sum2 == sum3) {
            return sum1;
        }

        if (sum1 >= sum2 && sum1 >= sum3) {
            sum1 -= h1[i];
            i++;
        } else if (sum2 >= sum1 && sum2 >= sum3) {
            sum2 -= h2[j];
            j++;
        } else {
            sum3 -= h3[k];
            k++;
        }

        if (i >= h1.size() || j >= h2.size() || k >= h3.size()) {
            return 0;
        }
    }
}

int main() {
    int n1, n2, n3;
    cin >> n1 >> n2 >> n3;

    vector<int> h1(n1);
    for (int i = 0; i < n1; ++i) {
        cin >> h1[i];
    }

    vector<int> h2(n2);
    for (int i = 0; i < n2; ++i) {
        cin >> h2[i];
    }

    vector<int> h3(n3);
    for (int i = 0; i < n3; ++i) {
        cin >> h3[i];
    }

    int result = equalStacks(h1, h2, h3);
    cout << result << endl;

    return 0;
}