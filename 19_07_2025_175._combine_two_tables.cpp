#include <iostream>
#include <vector>
#include <string>

using namespace std;

struct Person {
    int personId;
    string lastName;
    string firstName;
};

struct Address {
    int addressId;
    int personId;
    string address;
    string city;
    string state;
};

vector<vector<string>> combineTables(const vector<Person>& persons, const vector<Address>& addresses) {
    vector<vector<string>> result;

    for (const auto& person : persons) {
        bool foundAddress = false;
        for (const auto& address : addresses) {
            if (person.personId == address.personId) {
                result.push_back({person.firstName, person.lastName, address.city, address.state});
                foundAddress = true;
                break;
            }
        }

        if (!foundAddress) {
            result.push_back({person.firstName, person.lastName, "", ""});
        }
    }

    return result;
}