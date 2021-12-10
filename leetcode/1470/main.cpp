#include <vector>

using namespace std;

class Solution {
public:
  vector<int> shuffle(vector<int>& nums, int n) {
    vector<int> new_nums;
    for (int i = 0; i < n; i++) {
      new_nums.push_back(nums[i]);
      new_nums.push_back(nums[i + n]);
    }
    return new_nums;
  }
};