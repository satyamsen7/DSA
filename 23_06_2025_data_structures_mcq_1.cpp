#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
#include <queue>
#include <unordered_map>
#include <unordered_set>

using namespace std;

class Solution {
public:
    int solve() {
        int choice;
        cin >> choice;
        switch (choice) {
            case 1: return mcq1();
            case 2: return mcq2();
            case 3: return mcq3();
            case 4: return mcq4();
            case 5: return mcq5();
            case 6: return mcq6();
            case 7: return mcq7();
            case 8: return mcq8();
            case 9: return mcq9();
            case 10: return mcq10();
            default: return -1;
        }
    }

private:
    int mcq1() { return 2; }
    int mcq2() { return 4; }
    int mcq3() { return 1; }
    int mcq4() { return 3; }
    int mcq5() { return 2; }
    int mcq6() { return 4; }
    int mcq7() { return 1; }
    int mcq8() { return 3; }
    int mcq9() { return 2; }
    int mcq10() { return 4; }
};

int main() {
    Solution sol;
    cout << sol.solve() << endl;
    return 0;
}