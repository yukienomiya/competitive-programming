#include <string>
#include <map>

using namespace std;

class Solution {
public:
  map<char, int> getStringChars(const string& s) {
    map<char, int> chars;
    for (char ch : s) {
      int val = 0;
      if (chars.find(ch) != chars.end()) {
        val = chars[ch];
      }
      chars[ch] = val + 1;
    }
    return chars;
  }

  bool canConstruct(string ransomNote, string magazine) {
    map<char, int> string_chars = getStringChars(magazine);
    for (char ch : ransomNote) {
      if (string_chars.find(ch) == string_chars.end()) return false;
      string_chars[ch]--;
      if (string_chars[ch] == 0) string_chars.erase(ch);
    }
    return true;
  }
};