#include <iostream>
#include <vector>
#include <unordered_map>

class TwoSum {
private:
    std::vector<int> nums;
    std::unordered_map<int, int> counts;

public:
    TwoSum() {}

    void add(int number) {
        nums.push_back(number);
        counts[number]++;
    }

    bool find(int value) {
        for (auto const& [num, count] : counts) {
            int complement = value - num;
            if (counts.find(complement) != counts.end()) {
                if (num == complement) {
                    if (count > 1) {
                        return true;
                    }
                } else {
                    return true;
                }
            }
        }
        return false;
    }
};

int main() {
    TwoSum twoSum;

    twoSum.add(1);
    twoSum.add(3);
    twoSum.add(5);

    std::cout << twoSum.find(4) << std::endl;
    std::cout << twoSum.find(7) << std::endl;

    return 0;
}