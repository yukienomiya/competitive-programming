#include <string>
#include <unordered_map>

using namespace std;

class Solution {
public:
  bool compareMaps(unordered_map<char, int>& map1, unordered_map<char, int>& map2) {
    for (pair<char, int> p : map1) {
      if (map2.find(p.first) == map2.end()) {
        if (p.second > 3) return false;
      }
      else {
        if (abs(p.second - map2[p.first]) > 3) return false;
        map2.erase(p.first);
      }
    }
    return true;
  }

  bool checkAlmostEquivalent(string word1, string word2) {
    unordered_map<char, int> chars1, chars2;
    for (char& ch : word1) chars1[ch]++;
    for (char& ch : word2) chars2[ch]++;
    return compareMaps(chars1, chars2) && compareMaps(chars2, chars1);
  }
};