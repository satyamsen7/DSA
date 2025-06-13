#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>

using namespace std;

vector<int> matchingStrings(vector<string> strings, vector<string> queries) {
    unordered_map<string, int> stringCount;
    for (const string& str : strings) {
        stringCount[str]++;
    }

    vector<int> results;
    for (const string& query : queries) {
        results.push_back(stringCount[query]);
    }

    return results;
}

int main() {
    int n;
    cin >> n;

    vector<string> strings(n);
    for (int i = 0; i < n; ++i) {
        cin >> strings[i];
    }

    int q;
    cin >> q;

    vector<string> queries(q);
    for (int i = 0; i < q; ++i) {
        cin >> queries[i];
    }

    vector<int> result = matchingStrings(strings, queries);

    for (int i = 0; i < result.size(); ++i) {
        cout << result[i] << (i == result.size() - 1 ? "" : "\n");
    }
    cout << endl;

    return 0;
}