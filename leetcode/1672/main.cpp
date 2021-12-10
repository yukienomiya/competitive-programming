#include <vector>

using namespace std;

class Solution {
public:
  int maximumWealth(vector<vector<int>>& accounts) {
    int max_wealth = 0;
    int tot;
    for (const vector<int>& account : accounts) {
      tot = 0;
      for (const int& balance : account) {
        tot += balance;
      }
      max_wealth = max(max_wealth, tot);
    }
    return max_wealth;
  }
};