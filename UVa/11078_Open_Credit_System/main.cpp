#include <iostream>

using namespace std;

int main() {
  int cases;
  int n;
  cin >> cases;
  for (int i = 0; i < cases; i++) {
    cin >> n;
    int x1, x2;
    cin >> x1 >> x2;
    int max_so_far = max(x1, x2);
    int max_diff = x1 - x2;
    for (int i = 2; i < n; i++) {
      int x;
      cin >> x;
      if (max_so_far - x > max_diff) {
        max_diff = max_so_far - x;
      }
      if (x > max_so_far) {
        max_so_far = x;
      }
    }
    cout << max_diff << "\n";
  }
  return 0;
}