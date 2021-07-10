#include <iostream>
#include <cmath>

using namespace std;

int main() {
  int n;
  while (cin >> n) {
    bool b = true;
    int x1, x2;
    if (n == 1) {
      cin >> x1;
    }
    else {
      int nums[n - 1];
      for (int i = 0; i < n - 1; i++) {
        nums[i] = 0;
      }
      cin >> x1;
      for (int i = 1; i < n; i++) {
        cin >> x2;
        int x = abs(x1 - x2);
        nums[x - 1] = 1;
        x1 = x2;  
      }
      for (int i = 0; i < n - 1; i++) {
        if (nums[i] == 0) {
          b = false;
          break;
        }
      }
    }
    string res = b ? "Jolly" : "Not jolly";
    cout << res << endl;
  }
  return 0;
}