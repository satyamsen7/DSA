#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>

using namespace std;

vector<string> findDuplicateEmails(vector<string>& emails) {
    unordered_map<string, int> emailCount;
    vector<string> duplicateEmails;

    for (const string& email : emails) {
        emailCount[email]++;
        if (emailCount[email] == 2) {
            duplicateEmails.push_back(email);
        }
    }

    return duplicateEmails;
}

int main() {
    vector<string> emails = {"john.doe@example.com", "jane.doe@example.com", "john.doe@example.com", "alice.smith@example.com", "jane.doe@example.com"};
    vector<string> duplicateEmails = findDuplicateEmails(emails);

    for (const string& email : duplicateEmails) {
        cout << email << endl;
    }

    return 0;
}