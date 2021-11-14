class Solution {
public:
  int fib(int n) {
    if (n == 0) return 0;
    if (n == 1) return 1;
    int prepre = 0, pre = 1;
    for (int i = 0; i < n - 1; i++) {
      int x = prepre + pre;
      prepre = pre;
      pre = x;
    }
    return pre;
  }
};