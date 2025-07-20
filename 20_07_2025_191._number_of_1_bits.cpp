#include <iostream>

int hammingWeight(uint32_t n) {
    int count = 0;
    while (n) {
        n &= (n - 1);
        count++;
    }
    return count;
}

int main() {
    uint32_t num;
    std::cin >> num;
    std::cout << hammingWeight(num) << std::endl;
    return 0;
}