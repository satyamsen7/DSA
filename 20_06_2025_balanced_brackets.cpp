#include <iostream>
#include <stack>
#include <string>

using namespace std;

string isBalanced(string s) {
    stack<char> st;
    for (char c : s) {
        if (c == '(' || c == '[' || c == '{') {
            st.push(c);
        } else if (c == ')') {
            if (st.empty() || st.top() != '(') {
                return "NO";
            }
            st.pop();
        } else if (c == ']') {
            if (st.empty() || st.top() != '[') {
                return "NO";
            }
            st.pop();
        } else if (c == '}') {
            if (st.empty() || st.top() != '{') {
                return "NO";
            }
            st.pop();
        }
    }
    return st.empty() ? "YES" : "NO";
}

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        string s;
        getline(cin, s);
        cout << isBalanced(s) << endl;
    }
    return 0;
}