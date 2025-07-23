#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;

struct Email {
    int id;
    string email;
};

void deleteDuplicateEmails(vector<Email>& emails) {
    unordered_map<string, int> emailMap;
    vector<int> toDelete;

    for (const auto& email : emails) {
        if (emailMap.find(email.email) == emailMap.end()) {
            emailMap[email.email] = email.id;
        } else {
            if (email.id > emailMap[email.email]) {
                toDelete.push_back(email.id);
            } else {
                toDelete.push_back(emailMap[email.email]);
                emailMap[email.email] = email.id;
            }
        }
    }

    sort(toDelete.begin(), toDelete.end(), greater<int>());

    for (int id : toDelete) {
        for (size_t i = 0; i < emails.size(); ++i) {
            if (emails[i].id == id) {
                emails.erase(emails.begin() + i);
                break;
            }
        }
    }
}