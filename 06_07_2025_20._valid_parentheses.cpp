#include <iostream>
#include <stack>
#include <string>

using namespace std;

bool isValid(string s) {
    stack<char> st;
    for (char c : s) {
        if (c == '(' || c == '[' || c == '{') {
            st.push(c);
        } else {
            if (st.empty()) {
                return false;
            }
            char top = st.top();
            st.pop();
            if ((c == ')' && top != '(') ||
                (c == ']' && top != '[') ||
                (c == '}' && top != '{')) {
                return false;
            }
        }
    }
    return st.empty();
}

int main() {
    string s;
    cin >> s;
    cout << (isValid(s) ? "true" : "false") << endl;
    return 0;
}