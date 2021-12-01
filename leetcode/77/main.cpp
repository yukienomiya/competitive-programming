#include <vector>

using namespace std;

class Solution {
public:
  vector<vector<int>> combine(int n, int k) {
    vector<vector<int>> result;
    int i = 0;
    vector<int> comb(k, 0);
    while (i >= 0) {
      comb[i]++;
      if (comb[i] > n) --i;
      else if (i == k - 1) result.push_back(comb);
      else {
          ++i;
          comb[i] = comb[i - 1];
      }
    }
    return result;
  }
};