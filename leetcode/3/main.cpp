#include <string>
#include <set>

using namespace std;

class Solution {
public:
  int lengthOfLongestSubstring(string s) {
    set<char> substr_chars;
    int max_len = 0, len = 0;
    int left = 0, right = 0;
    while (right < size(s)) {
      while (substr_chars.find(s[right]) != substr_chars.end()) {
        substr_chars.erase(s[left]);
        left++;
        len--;
      }
      substr_chars.insert(s[right]);
      right++;
      len++;
      max_len = max(max_len, len);
    }
    return max_len;
  }
};