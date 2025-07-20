#include <iostream>
#include <vector>
#include <unordered_map>
#include <string>

using namespace std;

struct Customer {
    int id;
    string name;
};

struct Order {
    int id;
    int customerId;
};

vector<string> customersWhoNeverOrder(const vector<Customer>& customers, const vector<Order>& orders) {
    unordered_map<int, int> orderMap;
    for (const auto& order : orders) {
        orderMap[order.customerId]++;
    }

    vector<string> result;
    for (const auto& customer : customers) {
        if (orderMap.find(customer.id) == orderMap.end()) {
            result.push_back(customer.name);
        }
    }

    return result;
}

int main() {
    vector<Customer> customers = {
        {1, "Joe"},
        {2, "Henry"},
        {3, "Sam"},
        {4, "Max"}
    };

    vector<Order> orders = {
        {1, 3},
        {2, 1}
    };

    vector<string> result = customersWhoNeverOrder(customers, orders);

    for (const auto& name : result) {
        cout << name << endl;
    }

    return 0;
}