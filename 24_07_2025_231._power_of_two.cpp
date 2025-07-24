#include <iostream>

class Solution {
public:
    bool isPowerOfTwo(int n) {
        if (n <= 0) {
            return false;
        }
        return (n & (n - 1)) == 0;
    }
};

int main() {
    Solution sol;
    int n;
    std::cin >> n;
    bool result = sol.isPowerOfTwo(n);
    std::cout << (result ? "true" : "false") << std::endl;
    return 0;
}