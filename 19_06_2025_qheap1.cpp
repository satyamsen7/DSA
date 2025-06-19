#include <iostream>
#include <set>

int main() {
    int Q;
    std::cin >> Q;
    std::set<int> s;
    for (int i = 0; i < Q; ++i) {
        int type, value;
        std::cin >> type;
        if (type == 1) {
            std::cin >> value;
            s.insert(value);
        } else if (type == 2) {
            std::cin >> value;
            s.erase(value);
        } else {
            std::cout << *s.begin() << std::endl;
        }
    }
    return 0;
}