#include <iostream>
#include <string>
#include <stack>

using namespace std;

int main() {
    int q;
    cin >> q;

    string text = "";
    stack<string> history;

    for (int i = 0; i < q; ++i) {
        int type;
        cin >> type;

        if (type == 1) {
            string w;
            cin >> w;
            history.push(text);
            text += w;
        } else if (type == 2) {
            int k;
            cin >> k;
            history.push(text);
            text = text.substr(0, text.length() - k);
        } else if (type == 3) {
            int k;
            cin >> k;
            cout << text[k - 1] << endl;
        } else if (type == 4) {
            text = history.top();
            history.pop();
        }
    }

    return 0;
}