#include <vector>

using namespace std;

class Solution {
public:
  void reverseString(vector<char>& s) {
    int end = size(s) - 1;
    for (int i = 0; i < int(size(s) / 2); i++) {
      swap(s[i], s[end--]);
    }
  }
};