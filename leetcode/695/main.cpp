#include <vector>
#include <deque>
#include <iostream>

using namespace std;

class Solution {
public:
  int maxAreaOfIsland(vector<vector<int>>& grid) {
    int max_area = 0;
    vector<pair<int, int>> adjs = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};
    for (int r = 0; r < size(grid); r++) {
      for (int c = 0; c < size(grid[0]); c++) {
        if (grid[r][c] == 1) {
          int l = dfs(grid, adjs, r, c);
          max_area = max(max_area, l);
        }
      }
    }
    return max_area;
  }

  bool inBounds(vector<vector<int>>& grid, pair<int, int> pos) {
    return pos.first >= 0 && pos.first < size(grid) && pos.second >= 0 && pos.second < size(grid[0]);
  }

  int dfs(vector<vector<int>>& grid, vector<pair<int, int>>& adjs, int row, int col) {
    int area = 0;
    deque<pair<int, int>> stack;
    stack.push_back({row, col});
    while (!stack.empty()) {
      pair<int, int> pos = stack.back();
      stack.pop_back();
      if (grid[pos.first][pos.second] == 2) continue;
      grid[pos.first][pos.second] = 2;
      area++;
      for (pair<int, int> a : adjs) {
        pair<int, int> p = {pos.first + a.first, pos.second + a.second};
        if (inBounds(grid, p) && grid[p.first][p.second] == 1) {
          stack.push_back(p);
        }
      }
    }
    return area;
  }
};

int main() {
  vector<vector<int>> grid = {{0,0,1,0,0,0,0,1,0,0,0,0,0},{0,0,0,0,0,0,0,1,1,1,0,0,0},{0,1,1,0,1,0,0,0,0,0,0,0,0},{0,1,0,0,1,1,0,0,1,0,1,0,0},{0,1,0,0,1,1,0,0,1,1,1,0,0},{0,0,0,0,0,0,0,0,0,0,1,0,0},{0,0,0,0,0,0,0,1,1,1,0,0,0},{0,0,0,0,0,0,0,1,1,0,0,0,0}};
  Solution s;
  int area = s.maxAreaOfIsland(grid);
  cout << endl << area;
  return 0;
}