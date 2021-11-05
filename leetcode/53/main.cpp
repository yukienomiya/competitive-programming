#include <vector>

using namespace std;

class Solution {
public:
  int maxSubArray(vector<int>& nums) {
    int curr = nums[0], prev = nums[0], maxSum = nums[0];
    for (int i = 1; i < nums.size(); i++) {
      prev = curr = max(prev + nums[i], nums[i]);
      maxSum = max(maxSum, curr);
    }
    return maxSum;
  }
};

// class Solution {
// public:
//   int maxSubArray(vector<int>& nums) {
//     int n = nums.size(), max = nums[0];
//     vector<vector<int>> matrix(n, vector<int>(n, 0));
//     matrix[0][0] = nums[0];
//     for (int i = 1; i < n; i++) {
//       int x = matrix[0][i - 1] + nums[i];
//       matrix[0][i] = x;
//       if (x > max) max = x;
//     }
//     for (int row = 1; row < n; row++) {
//       int elem = matrix[row - 1][row - 1];
//       for (int col = row; col < n; col++) {
//         int x = matrix[row - 1][col] - elem;
//         matrix[row][col] = x;
//         if (x > max) max = x;
//       }
//     }
//     return max;
//   }
// };

int main() {
  return 0;
}