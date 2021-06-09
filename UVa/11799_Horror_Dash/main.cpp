#include <iostream>

using namespace std;

int main() {
  int count = 1;
  int cases, speeds, x, max;
  cin >> cases;
  while (count <= cases) {
    cin >> speeds;
    max = 0;
    while (speeds--) {
      cin >> x;
      if (x > max) {
        max = x;
      }
    }
    cout << "Case " << count << ": " << max << "\n";
    count++;
  }
  return 0;
}