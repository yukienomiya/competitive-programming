#include <vector>
#include <cmath>

using namespace std;

class Solution {
  public:
    int searchInsert(vector<int>& nums, int target) {
      int start = 0, end = size(nums) - 1, mid;
      while (start <= end) {
        mid = int(floor(double(start + end) / 2));
        if (nums[mid] < target) start = mid + 1;
        else if (nums[mid] > target) end = mid - 1;
        else return mid;
      }
      return start;
    }
};