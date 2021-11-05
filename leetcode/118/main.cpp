#include <vector>

using namespace std;

class Solution {
public:
  vector<vector<int>> generate(int numRows) {
    vector<vector<int>> triangle;
    triangle.push_back(vector<int>(1, 1));
    for (int idx = 1; idx < numRows; idx++) {
      vector<int> row(idx + 1, 1);
      for (int j = 1; j < idx; j++) {
        row[j] = triangle[idx - 1][j - 1] + triangle[idx - 1][j];
      }
      triangle.push_back(row);
    }
    return triangle;
  }
};