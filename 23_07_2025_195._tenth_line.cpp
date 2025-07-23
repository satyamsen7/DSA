#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

int main(int argc, char *argv[]) {
  if (argc != 2) {
    return 1;
  }

  string filename = argv[1];
  ifstream inputFile(filename);

  if (!inputFile.is_open()) {
    return 1;
  }

  string line;
  int lineNumber = 0;

  while (getline(inputFile, line)) {
    lineNumber++;
    if (lineNumber == 10) {
      cout << line << endl;
      break;
    }
  }

  inputFile.close();

  return 0;
}