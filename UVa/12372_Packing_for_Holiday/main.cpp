#include <iostream>

using namespace std;

int main() {
  int count = 0;
  int cases, l, w, h;
  cin >> cases;
  while (cases--) {
    count++;
    cin >> l >> w >> h;
    if (l <= 20 && w <= 20 && h <= 20) {
      cout << "Case " << count << ": good\n";
    }
    else {
      cout << "Case " << count << ": bad\n";
    }
  }
  return 0;
}