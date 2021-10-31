#include <string>
#include <iostream>

using namespace std;

class Solution {
public:
  int countBinarySubstrings(string s) {
    int val = s[0], pre = 0, cur = 0, tot = 0, idx = 0;
    while (idx < size(s) && s[idx] == val) {
      if (idx == size(s) - 1) return 0;
      pre++;
      idx++;
    }
    val = s[idx];
    while (idx < size(s)) {
      if (s[idx] != val) {
        if (idx == size(s) - 1) return tot += min(pre, cur) + 1;
        tot += min(pre, cur);
        pre = cur;
        cur = 1;
        val = s[idx];
      }
      else cur++;
      idx++;
    }
    return tot += min(pre, cur);
  }
};

int main() {
  Solution s;
  cout << s.countBinarySubstrings("00110011");
}