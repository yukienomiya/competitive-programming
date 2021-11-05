#include <vector>

using namespace std;

class Solution {
public:
  int maxProfit(vector<int>& prices) {
    int min_so_far = prices[0], max_profit = 0;
    for (int i = 1; i < prices.size(); i++) {
      if (prices[i] - min_so_far > max_profit) max_profit = prices[i] - min_so_far;
      if (prices[i] < min_so_far) min_so_far = prices[i];
    }
    return max_profit;
  }
};