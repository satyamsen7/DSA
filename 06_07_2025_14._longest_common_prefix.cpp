#include <iostream>
#include <vector>
#include <string>

using namespace std;

string longestCommonPrefix(vector<string>& strs) {
    if (strs.empty()) {
        return "";
    }

    string prefix = strs[0];
    for (size_t i = 1; i < strs.size(); ++i) {
        while (strs[i].find(prefix) != 0) {
            prefix = prefix.substr(0, prefix.length() - 1);
            if (prefix.empty()) {
                return "";
            }
        }
    }
    return prefix;
}

int main() {
    vector<string> strs1 = {"flower", "flow", "flight"};
    cout << longestCommonPrefix(strs1) << endl;

    vector<string> strs2 = {"dog", "racecar", "car"};
    cout << longestCommonPrefix(strs2) << endl;

    vector<string> strs3 = {"cir", "car"};
    cout << longestCommonPrefix(strs3) << endl;

    vector<string> strs4 = {"", "b"};
    cout << longestCommonPrefix(strs4) << endl;

    return 0;
}