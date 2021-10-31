#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
  int numberOfSubarrays(vector<int>& nums, int k) {
    int tot = 0, count = 0, odds = 0, begin = 0;
    for (int i = 0; i < nums.size(); i++) {
      if (nums[i] & 1) {
        odds++;
        if (odds >= k) {
          count = 1;
          while (!(nums[begin++] & 1)) count++;
          tot += count;
        }
      }
      else if (odds >= k) tot += count;
    }
    return tot;
  }
};

int main() {
  Solution s;
  vector<int> n = {2,2,2,1,2,2,1,2,2,2};
  int x = s.numberOfSubarrays(n, 2);
  cout << x;
}