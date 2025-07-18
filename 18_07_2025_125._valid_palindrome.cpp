#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

bool isPalindrome(string s) {
    string cleaned_s = "";
    for (char c : s) {
        if (isalnum(c)) {
            cleaned_s += tolower(c);
        }
    }

    int left = 0;
    int right = cleaned_s.length() - 1;

    while (left < right) {
        if (cleaned_s[left] != cleaned_s[right]) {
            return false;
        }
        left++;
        right--;
    }

    return true;
}

int main() {
    string s1 = "A man, a plan, a canal: Panama";
    cout << isPalindrome(s1) << endl;

    string s2 = "race a car";
    cout << isPalindrome(s2) << endl;

    string s3 = " ";
    cout << isPalindrome(s3) << endl;

    return 0;
}