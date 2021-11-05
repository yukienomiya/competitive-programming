#include <vector>
#include <bitset>

using namespace std;

class Solution {
public:
  bool check(const vector<vector<char>>& board, bitset<9>& numbers, int row, int col){
    if (board[row][col] != '.') {
      int num = board[row][col] - '0';
      if (numbers.test(num - 1)) return false;
      numbers.set(num - 1);
    }
    return true;
  }

  bool checkSquares(const vector<vector<char>>& board) {
    for (int i = 0; i < 9; i += 3) {
      for (int j = 0; j < 9; j += 3) {
        bitset<9> nums;
        for (int x = 0; x < 3; x++) {
          for (int y = 0; y < 3; y++) {
            if (!check(board, nums, i + x, j + y)) return false;
          }
        }
      }
    }
    return true;
  }

  bool isValidSudoku(vector<vector<char>>& board) {
    for (int i = 0; i < 9; i++) {
      bitset<9> numbers_in_row, numbers_in_col;
      for (int j = 0; j < 9; j++) {
        if (!check(board, numbers_in_row, i, j)) return false;
        if (!check(board, numbers_in_col, j, i)) return false;
      }
    }
    return checkSquares(board);
  }
};