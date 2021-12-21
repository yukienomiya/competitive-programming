#include <vector>
#include <cmath>

using namespace std;

class Solution {
public:
  void rotate(vector<vector<int>>& matrix) {
    for (int row = 0; row < matrix.size(); row++) {
      for (int col = row; col < matrix[0].size(); col++) {
        swap(matrix[row][col], matrix[col][row]);
      }
    }
    int no_columns = matrix[0].size();
    for (int row = 0; row < matrix.size(); row++) {
      for (int col = 0; col < int(floor(no_columns / 2)); col++) {
        swap(matrix[row][col], matrix[row][no_columns - 1 - col]);
      }
    }
  }
};