#include <iostream>

using namespace std;

int main() {
  int cases;
  cin >> cases;
  int count = 0;
  while (cases--) {
    bool within_limits = false;
    float length, width, depth, weight;
    cin >> length >> width >> depth >> weight;
    float measures_sum = length + width + depth;
    if (weight <= 7.0) {
      if ((length <= 56.0 && width <= 45.0 && depth <= 25.0) || (measures_sum <= 125.0)) {
        within_limits = true;
      }
    }
    if (within_limits) {
      cout << 1;
      count++;
    }
    else {
      cout << 0;
    }
    cout << "\n";
  }
  cout << count << "\n";
  return 0;
}