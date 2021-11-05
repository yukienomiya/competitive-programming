#include <vector>
#include <cmath>

using namespace std;

class Solution {
public:
  pair<int, int> toMatrix(int idx, int rows, int cols) {
    int r = int(floor(idx / cols));
    int c = idx % cols;
    return {r, c};
  }

  bool binarySearch(const vector<vector<int>>& matrix, const int& r, const int& c, const int& target, int begin, int end) {
    if (begin > end) return false;
    int middle = int(floor((begin + end) / 2));
    pair<int, int> indexes = toMatrix(middle, r, c);
    int val = matrix[indexes.first][indexes.second];
    if (val == target) return true;
    if (val > target) return binarySearch(matrix, r, c, target, begin, middle - 1);
    return binarySearch(matrix, r, c, target, middle + 1, end);
  }

  bool searchMatrix(vector<vector<int>>& matrix, int target) {
    int total_cells = matrix.size() * matrix[0].size();
    return binarySearch(matrix, matrix.size(), matrix[0].size(), target, 0, total_cells - 1);
  }
};