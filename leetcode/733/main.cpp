#include <vector>
#include <deque>
#include <iostream>

using namespace std;

class Solution {
public:
  vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
    if (image[sr][sc] == newColor) return image;
    vector<pair<int, int>> adjs = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};
    deque<pair<int, int>> stack;
    stack.push_back({sr, sc});
    dfs(image, stack, adjs, image[sr][sc], newColor);
    return image;
  }

  bool inBounds(pair<int, int>& p, int rows, int cols) {
    return p.first >= 0 && p.first < rows && p.second >= 0 && p.second < cols;
  }

  void dfs(vector<vector<int>>& image, deque<pair<int, int>>& stack, vector<pair<int, int>>& adjs, int oldCol, int& newCol) {
    while (!stack.empty()) {
      pair<int, int> elem = stack.back();
      stack.pop_back();
      int r = elem.first, c = elem.second;
      image[r][c] = newCol;
      for (pair<int, int> a : adjs) {
        pair<int, int> p = make_pair(r + a.first, c + a.second);
        if (inBounds(p, size(image), size(image[0])) && image[p.first][p.second] == oldCol) {
          stack.push_back(p);
        }
      }
    }
  }
};

int main() {
  vector<vector<int>> image = {{1,1,1},{1,1,0},{1,0,1}};
  int sr = 1, sc = 1, newColor = 2;
  Solution s;
  vector<vector<int>> img = s.floodFill(image, sr, sc, newColor);
  for (vector<int> r : img) {
    for (int el : r) {
      cout << el << " ";
    }
    cout << endl;
  }
}