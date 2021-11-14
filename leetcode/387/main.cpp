#include <string>
#include <set>
#include <map>

using namespace std;

class Solution {
public:
  int firstUniqChar(string s) {
    map<char, int> string_chars;
    set<char> repeated_chars;
    for (int i = 0; i < s.size(); i++) {
      if (string_chars.find(s[i]) != string_chars.end()) repeated_chars.insert(s[i]);
      else string_chars.insert({s[i], i});
    }
    int res = s.size();
    for (pair<char, int> ch : string_chars) {
      if (repeated_chars.find(s[ch.second]) == repeated_chars.end() && ch.second < res) res = ch.second;
    }
    if (res == s.size()) return -1;
    return res;
  }
};