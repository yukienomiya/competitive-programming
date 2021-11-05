#include <bits/stdc++.h>
#include <vector>
#include <set>

using namespace std;

class Solution {
public:
  bool containsDuplicate(vector<int>& nums) {
    sort(nums.begin(), nums.end());
    for (int i = 1; i < nums.size(); i++) {
      if (nums[i] == nums[i - 1]) return true;
    }
    return false;
  }
};

// class Solution {
// public:
//   bool containsDuplicate(vector<int>& nums) {
//     set<int> elements(nums.begin(), nums.end());
//     return elements.size() == nums.size();
//   }
// };

// class Solution {
// public:
//   bool containsDuplicate(vector<int>& nums) {
//     set<int> elements;
//     for (int n : nums) {
//       if (elements.find(n) != elements.end()) return true;
//       elements.insert(n);
//     }
//     return false;
//   }
// };