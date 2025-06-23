#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool isPrime(int n) {
    if (n <= 1) return false;
    for (int i = 2; i * i <= n; ++i) {
        if (n % i == 0) return false;
    }
    return true;
}

vector<int> generatePrimes(int q) {
    vector<int> primes;
    int num = 2;
    while (primes.size() < q) {
        if (isPrime(num)) {
            primes.push_back(num);
        }
        num++;
    }
    return primes;
}

int main() {
    int n, q;
    cin >> n >> q;

    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    vector<int> primes = generatePrimes(q);
    vector<vector<int>> ans(q + 1);

    for (int i = 0; i <= q; ++i) {
        vector<int> temp;
        for (int j = a.size() - 1; j >= 0; --j) {
            if (i == 0) {
                temp.push_back(a[j]);
            }
            else if (a[j] % primes[i - 1] == 0) {
                ans[i].push_back(a[j]);
            }
            else {
                temp.push_back(a[j]);
            }
        }
        a = temp;
    }

    for (int i = 1; i <= q; ++i) {
        for (int num : ans[i]) {
            cout << num << endl;
        }
    }
    
    for (int i = a.size() - 1; i >= 0; --i) {
        cout << a[i] << endl;
    }

    return 0;
}