#include <vector>
#include <algorithm>

using namespace std;

class Solution {
  public:
    vector<int> sortedSquares(vector<int>& nums) {
      if (nums[0] >= 0) return squareArray(nums);
      if (nums[size(nums) - 1] <= 0) {
        reverse(nums.begin(), nums.end());
        return squareArray(nums);
      }

      vector<int> new_nums;
      int pos = getIdxFirstPositive(nums);
      int neg = pos - 1;

      for (int i = 0; i < size(nums); i++) {
        if (neg < 0 || (pos < size(nums) && nums[pos] < nums[neg] * -1)) {
          new_nums.push_back(nums[pos]);
          pos++;
        }
        else {
          new_nums.push_back(nums[neg] * -1);
          neg--;
        }
      }
      return squareArray(new_nums);
    }

    int getIdxFirstPositive(vector<int>& nums) {
      for (int i = 1; i < size(nums); i++) {
        if (nums[i] >= 0) return i;
      }
      return -1;
    }

    vector<int> squareArray(vector<int>& nums) {
      for (int i = 0; i < size(nums); i++) {
        nums[i] = nums[i] * nums[i];
      }
      return nums;
    }
};