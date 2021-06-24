#include <iostream>

using namespace std;

int main() {
  int height, width;

  while (cin >> height >> width) {
    if (height == 0 && width == 0) {
      break;
    }
    int heights[width + 1];
    for (int i = 0; i < width; i++) {
      cin >> heights[i];
    }
    heights[width] = height;
    int tot = 0;
    for (int i = 1; i < width + 1; i++) {
      int x = heights[i] - heights[i - 1];
      if (x > 0) {
        tot += x;
      }
    }
    cout << tot << "\n";
  }
  return 0;
}