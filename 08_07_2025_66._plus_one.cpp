#include <vector>

std::vector<int> plusOne(std::vector<int>& digits) {
    int n = digits.size();
    for (int i = n - 1; i >= 0; --i) {
        if (digits[i] < 9) {
            digits[i]++;
            return digits;
        }
        digits[i] = 0;
    }
    std::vector<int> newNumber(n + 1, 0);
    newNumber[0] = 1;
    return newNumber;
}