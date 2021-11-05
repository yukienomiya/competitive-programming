#include <vector>

using namespace std;

class Solution {
public:
  vector<vector<int>> matrixReshape(vector<vector<int>>& mat, int r, int c) {
    vector<vector<int>> reshaped_mat(r, vector<int>(c, 0));
    if (mat.size() * mat[0].size() != r * c) return mat;
    int row_idx = 0, col_idx = 0;
    for (int row = 0; row < mat.size(); row++) {
      for (int col = 0; col < mat[0].size(); col++) {
        if (col_idx == c) {
          col_idx = 0;
          row_idx++;
        }
        reshaped_mat[row_idx][col_idx++] = mat[row][col];
      }
    }
    return reshaped_mat;
  }
};