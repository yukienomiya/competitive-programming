#include <string>
#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
  bool checkInclusion(string s1, string s2) {
    if (size(s1) > size(s2)) return false;
    vector<int> elems1(26, 0), elems2(26, 0);
    int start = 0, end = size(s1) - 1;
    for (int i = start; i < end + 1; i++) {
      elems1[s1[i] - 97]++;
      elems2[s2[i] - 97]++;
    }
    while (end < size(s2) - 1) {
      if (containSameElements(elems1, elems2)) return true;
      elems2[s2[start++] - 97]--;
      elems2[s2[++end] - 97]++;
    }
    return containSameElements(elems1, elems2);
  }

  bool containSameElements(vector<int> elems1, vector<int> elems2) {
    for (int i = 0; i < 26; i++) {
      if (elems1[i] != elems2[i]) return false;
    }
    return true;
  }
};

// Slow solution
//
// class Solution {
// public:
//   bool checkInclusion(string s1, string s2) {
//     if (size(s1) > size(s2)) return false;
//     map<char, int> elems1, elems2;
//     int start = 0, end = size(s1) - 1;
//     for (int i = start; i < end + 1; i++) {
//       elems1[s1[i]]++;
//       elems2[s2[i]]++;
//     }
//     while (end < size(s2) - 1) {
//       if (containSameElements(elems1, elems2)) return true;
//       elems2[s2[start++]]--;
//       elems2[s2[++end]]++;
//     }
//     return containSameElements(elems1, elems2);
//   }

//   bool containSameElements(map<char, int>& elems1, map<char, int>& elems2) {
//     for (auto it = elems1.begin(); it != elems1.end(); it++) {
//       if (elems2.find(it->first) == elems2.end() || it->second != elems2[it->first]) return false;
//     }
//     return true;
//   }
// };