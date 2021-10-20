#include <cmath>

using namespace std;

// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

class Solution {
public:
  int firstBadVersion(int n) {
    int left = 0, right = n;
    long long mid;
    while (left <= right) {
      if (left == right) return left;
      mid = int(floor(double(right - left) / 2)) + left;
      if (isBadVersion(mid)) right = mid;
      else left = mid + 1;
    }
    return mid;
  }
};