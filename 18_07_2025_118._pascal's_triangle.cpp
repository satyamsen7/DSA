#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> generatePascalTriangle(int numRows) {
    vector<vector<int>> triangle;
    if (numRows <= 0) {
        return triangle;
    }

    triangle.push_back({1});

    for (int i = 1; i < numRows; ++i) {
        vector<int> row;
        row.push_back(1);

        for (int j = 1; j < i; ++j) {
            row.push_back(triangle[i - 1][j - 1] + triangle[i - 1][j]);
        }

        row.push_back(1);
        triangle.push_back(row);
    }

    return triangle;
}

int main() {
    int numRows;
    cin >> numRows;

    vector<vector<int>> pascalTriangle = generatePascalTriangle(numRows);

    for (const auto& row : pascalTriangle) {
        for (int val : row) {
            cout << val << " ";
        }
        cout << endl;
    }

    return 0;
}