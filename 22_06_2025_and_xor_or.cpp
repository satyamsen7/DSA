#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int a, b;
        cin >> a >> b;
        cout << (a & b) << " " << (a ^ b) << " " << (a | b) << endl;
    }
    return 0;
}