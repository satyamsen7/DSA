#include <iostream>
#include <vector>

using namespace std;

vector<double> polynomialDivision(const vector<double>& dividend, const vector<double>& divisor, vector<double>& quotient, vector<double>& remainder) {
    int n = dividend.size() - 1;
    int m = divisor.size() - 1;

    if (m > n) {
        remainder = dividend;
        quotient.clear();
        return remainder;
    }

    quotient.resize(n - m + 1, 0.0);
    remainder = dividend;

    for (int i = n - m; i >= 0; --i) {
        quotient[i] = remainder[n - m + i] / divisor[m];

        for (int j = 0; j <= m; ++j) {
            remainder[n - m + i - j] -= quotient[i] * divisor[m - j];
        }
    }

    remainder.resize(m);
    return remainder;
}

int main() {
    vector<double> dividend, divisor, quotient, remainder;
    int n, m;

    cin >> n;
    dividend.resize(n + 1);
    for (int i = 0; i <= n; ++i) {
        cin >> dividend[i];
    }

    cin >> m;
    divisor.resize(m + 1);
    for (int i = 0; i <= m; ++i) {
        cin >> divisor[i];
    }

    polynomialDivision(dividend, divisor, quotient, remainder);

    cout << quotient.size() -1 << endl;
    for (int i = 0; i < quotient.size(); ++i) {
        cout << quotient[i] << (i == quotient.size() - 1 ? "" : " ");
    }
    cout << endl;

    cout << remainder.size() - 1 << endl;
    for (int i = 0; i < remainder.size(); ++i) {
        cout << remainder[i] << (i == remainder.size() - 1 ? "" : " ");
    }
    cout << endl;

    return 0;
}