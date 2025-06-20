#include <iostream>
#include <algorithm>

int main() {
    int n;
    std::cin >> n;
    int max_element = -1000000001;
    for (int i = 0; i < n; ++i) {
        int element;
        std::cin >> element;
        max_element = std::max(max_element, element);
    }
    std::cout << max_element << std::endl;
    return 0;
}