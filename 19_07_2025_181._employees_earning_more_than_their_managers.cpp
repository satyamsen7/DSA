#include <iostream>
#include <vector>
#include <string>

using namespace std;

struct Employee {
    int id;
    string name;
    int salary;
    int managerId;
};

vector<string> findHighEarningEmployees(const vector<Employee>& employees) {
    vector<string> result;
    for (const auto& emp : employees) {
        if (emp.managerId != -1) {
            for (const auto& manager : employees) {
                if (manager.id == emp.managerId && emp.salary > manager.salary) {
                    result.push_back(emp.name);
                    break;
                }
            }
        }
    }
    return result;
}

int main() {
    vector<Employee> employees = {
        {1, "Joe", 70000, 3},
        {2, "Henry", 80000, 4},
        {3, "Sam", 60000, -1},
        {4, "Max", 90000, -1}
    };

    vector<string> highEarningEmployees = findHighEarningEmployees(employees);

    for (const auto& name : highEarningEmployees) {
        cout << name << endl;
    }

    return 0;
}