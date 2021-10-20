#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int bin_search_recursive(int idx_start, int idx_end, vector<int> &nums, int target) {
  int idx_middle = int(floor((double(idx_start + idx_end)) / 2));
  if (nums[idx_middle] == target) return idx_middle;
  if (idx_end - idx_start == 0) return -1;
  if (nums[idx_middle] > target) {
    return bin_search_recursive(idx_start, idx_middle, nums, target);
  }
  return bin_search_recursive(idx_middle + 1, idx_end, nums, target);
}

int bin_search_iterative(vector<int> &nums, int target) {
  int left = 0, right = size(nums) - 1, middle;
  while (left <= right) {
    middle = int(floor((double(left + right)) / 2));
    if (nums[middle] == target) return middle;
    else if (nums[middle] > target) right = middle - 1;
    else left = middle + 1;
  }
  return -1;
}