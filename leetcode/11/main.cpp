#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
  int maxArea(vector<int>& height) {
    int begin = 0, end = height.size() - 1;
    int max_tot = 0, tot = 0;
    while (begin < end) {
      tot = min(height[begin], height[end]) * (end - begin);
      max_tot = max(max_tot, tot);
      if (height[begin] > height[end]) end--;
      else begin++;
    }
    return max_tot;
  }
};