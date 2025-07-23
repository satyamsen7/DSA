#include <iostream>
#include <fstream>
#include <string>
#include <regex>
#include <vector>

using namespace std;

vector<string> validPhoneNumbers(const string& filename) {
    ifstream file(filename);
    string line;
    vector<string> result;

    if (file.is_open()) {
        regex pattern1(R"(\b\d{3}-\d{3}-\d{4}\b)");
        regex pattern2(R"(\b\(\d{3}\) \d{3}-\d{4}\b)");

        while (getline(file, line)) {
            if (regex_match(line, pattern1) || regex_match(line, pattern2)) {
                result.push_back(line);
            }
        }
        file.close();
    }

    return result;
}

int main() {
    
    ofstream temp_file("phone_numbers.txt");
    if (temp_file.is_open()) {
        temp_file << "987-123-4567\n";
        temp_file << "123 456 7890\n";
        temp_file << "(123) 456-7890\n";
        temp_file.close();
    } else {
        cerr << "Unable to create temporary file." << endl;
        return 1;
    }
    
    vector<string> validNumbers = validPhoneNumbers("phone_numbers.txt");

    for (const string& number : validNumbers) {
        cout << number << endl;
    }
    
    remove("phone_numbers.txt");

    return 0;
}