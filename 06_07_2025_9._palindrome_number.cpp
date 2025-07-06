#include <algorithm>

class Solution {
public:
    bool isPalindrome(int x) {
        if (x < 0) return false;
        if (x == 0) return true;

        std::string s = std::to_string(x);
        std::string reversed_s = s;
        std::reverse(reversed_s.begin(), reversed_s.end());

        return s == reversed_s;
    }
};