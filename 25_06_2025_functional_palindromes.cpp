#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

bool isPalindrome(const string& s) {
    string temp = s;
    reverse(temp.begin(), temp.end());
    return s == temp;
}

int solve() {
    int n;
    cin >> n;
    string s;
    cin >> s;

    int count = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = i; j < n; ++j) {
            string sub = s.substr(i, j - i + 1);
            if (isPalindrome(sub)) {
                count++;
            }
        }
    }

    return count;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        cout << solve() << endl;
    }
    return 0;
}