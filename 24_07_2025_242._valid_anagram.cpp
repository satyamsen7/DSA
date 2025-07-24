#include <iostream>
#include <string>
#include <algorithm>
#include <unordered_map>

using namespace std;

bool isAnagram(string s, string t) {
  if (s.length() != t.length()) {
    return false;
  }

  unordered_map<char, int> s_counts;
  unordered_map<char, int> t_counts;

  for (char c : s) {
    s_counts[c]++;
  }

  for (char c : t) {
    t_counts[c]++;
  }

  return s_counts == t_counts;
}