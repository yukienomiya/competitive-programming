#include <vector>

using namespace std;

class Solution {
public:
  void moveZeroes(vector<int> &nums) {
    int zero = -1;
    for (int i = 0; i < size(nums); i++) {
      if (zero < 0 && nums[i] == 0) zero = i;
      if (nums[i] != 0 && zero >= 0) {
        swap(nums[zero++], nums[i]);
      }
    }
  }
};