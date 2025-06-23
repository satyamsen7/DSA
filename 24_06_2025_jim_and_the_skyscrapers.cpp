#include <iostream>
#include <vector>
#include <stack>

using namespace std;

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;

        vector<int> h(n);
        for (int i = 0; i < n; ++i) {
            cin >> h[i];
        }

        long long count = 0;
        stack<int> st;

        for (int i = 0; i < n; ++i) {
            while (!st.empty() && h[i] > h[st.top()]) {
                st.pop();
            }

            if (!st.empty() && h[i] == h[st.top()]) {
                count++;
            }

            st.push(i);
        }

        while (!st.empty()) {
            st.pop();
        }

        for (int i = n - 1; i >= 0; --i) {
            while (!st.empty() && h[i] > h[st.top()]) {
                st.pop();
            }

            if (!st.empty() && h[i] == h[st.top()]) {
                count++;
            }

            st.push(i);
        }

        cout << count << endl;
    }

    return 0;
}