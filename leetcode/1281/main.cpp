#include <vector>

using namespace std;

class Solution {
public:
  vector<int> getDigits(int n) {
    vector<int> digits;
    while (n > 0) {
      digits.push_back(n % 10);
      n /= 10;
    }
    return digits;
  }

  int subtractProductAndSum(int n) {
    vector<int> digits = getDigits(n);
    int sum = 0, prod = 1;
    for (const int& digit : digits) {
      sum += digit;
      prod *= digit;
    }
    return prod - sum;
  }
};