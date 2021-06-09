#include <iostream>

using namespace std;

int main() {
  int cases, walls, a, b;
  int count = 0;
  cin >> cases;
  while (count < cases) {
    cin >> walls;
    cin >> a;
    int hi = 0, lo = 0;
    while (walls > 1) {
      cin >> b;
      if (a < b) {
        hi++;
      }
      else if (a > b) {
        lo++;
      }
      a = b;
      walls--;
    }
    count++;
    cout << "Case " << count << ": " << hi << " " << lo << "\n";
  }
  return 0;
}