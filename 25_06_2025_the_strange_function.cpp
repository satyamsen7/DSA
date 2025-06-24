#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int strange_function(int n) {
    vector<int> digits;
    int temp = n;
    while (temp > 0) {
        digits.push_back(temp % 10);
        temp /= 10;
    }
    reverse(digits.begin(), digits.end());

    if (digits.empty()) {
        return 0;
    }

    int min_digit = digits[0];
    int max_digit = digits[0];

    for (int digit : digits) {
        min_digit = min(min_digit, digit);
        max_digit = max(max_digit, digit);
    }

    return max_digit - min_digit;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        cout << strange_function(n) << endl;
    }
    return 0;
}