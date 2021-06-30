#include <iostream>
#include <math.h>

using namespace std;

int main() {
  int N, first, second;
  while (cin >> N >> first >> second) {
    if (second < first) {
      int x = first;
      first = second;
      second = x;
    }
    if (second - first == 1 && first % 2 == 1) {
      cout << 1 << "\n";
      continue;
    }
    int sol = N, start = 1, end = int(pow(2.0, N));
    while (true) {
      int half_n = start + floor((end - start) / 2);
      if (first <= half_n && second > half_n) {
        break;
      }
      else if (first < half_n && second <= half_n) {
        end = half_n;
      }
      else {
        start = half_n + 1;
      }
      sol--;
    }
    cout << sol << "\n";
  }
  return 0;
}