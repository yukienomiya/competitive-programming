#include <string>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

class Solution {
public:
  bool isAnagram(string s, string t) {
    int len1 = s.size(), len2 = t.size();
    if (len1 != len2) return false;
    sort(s.begin(), s.end());
    sort(t.begin(), t.end());
    for (int i = 0; i < len1; i++) {
      if (s[i] != t[i]) return false;
    }
    return true;
  }
};

// class Solution {
// public:
//   map<char, int> getStringChars(const string& s) {
//     map<char, int> chars;
//     for (char ch : s) {
//       int val = 0;
//       if (chars.find(ch) != chars.end()) {
//         val = chars[ch];
//       }
//       chars[ch] = val + 1;
//     }
//     return chars;
//   }

//   bool isAnagram(string s, string t) {
//     map<char, int> s_letters = getStringChars(s);
//     map<char, int> t_letters = getStringChars(t);
//     for (pair<char, int> ch : t_letters) {
//       if (s_letters.find(ch.first) == s_letters.end()) return false;
//       if (s_letters[ch.first] != ch.second) return false;
//       s_letters.erase(ch.first);
//     }
//     return s_letters.empty();
//   }
// };