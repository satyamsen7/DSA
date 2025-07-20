#include <iostream>
#include <cstdint>

uint32_t reverseBits(uint32_t n) {
    uint32_t reversed = 0;
    for (int i = 0; i < 32; ++i) {
        reversed |= (n & 1) << (31 - i);
        n >>= 1;
    }
    return reversed;
}

int main() {
    uint32_t num = 43261596;
    uint32_t reversedNum = reverseBits(num);
    std::cout << reversedNum << std::endl;
    return 0;
}