#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

int romanToInt(string s) {
    unordered_map<char, int> romanMap = {
        {'I', 1},
        {'V', 5},
        {'X', 10},
        {'L', 50},
        {'C', 100},
        {'D', 500},
        {'M', 1000}
    };

    int result = 0;
    int n = s.length();

    for (int i = 0; i < n; ++i) {
        if (i < n - 1 && romanMap[s[i]] < romanMap[s[i + 1]]) {
            result -= romanMap[s[i]];
        } else {
            result += romanMap[s[i]];
        }
    }

    return result;
}

int main() {
    string romanNumeral;
    cin >> romanNumeral;

    int integerValue = romanToInt(romanNumeral);
    cout << integerValue << endl;

    return 0;
}