#include <vector>

using namespace std;

class Solution {
public:
  vector<int> twoSum(vector<int>& numbers, int target) {
    int start = 0, end = size(numbers) - 1;
    while (start < end) {
      int tot = numbers[start] + numbers[end];
      if (tot == target) break;
      else if (tot > target) end--;
      else start++;
    }
    vector<int> result{start + 1, end + 1};
    return result;
  }
};