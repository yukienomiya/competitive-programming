#include <vector>

using namespace std;

class Solution {
public:
  void rotate(vector<int> &nums, int k) {
    vector<int> nums2 = nums;
    int l = size(nums);
    for (int i = 0; i < l; i++) {
      nums2[(i + k) % l] = nums[i];
    }
    nums = nums2;
  }
};