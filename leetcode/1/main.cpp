#include <vector>
#include <unordered_map>
#include <iostream>

using namespace std;

class Solution {
public:
  vector<int> twoSum(vector<int>& nums, int target) {
    vector<int> res;
    unordered_map<int, int> complements;
    for (int i = 0; i < nums.size(); i++) {
      int complement = target - nums[i];
      if (complements.find(nums[i]) != complements.end()) {
        res.push_back(complements.at(nums[i]));
        res.push_back(i);
        break;
      }
      complements.insert({complement, i});
    }
    return res;
  }
};

int main() {
  Solution s;
  vector<int> v{2, 7, 11, 15};
  vector<int> res = s.twoSum(v, 9);
  for (int x : res) {
    cout << x << " ";
  }
  return 0;
}