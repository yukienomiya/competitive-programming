#include <iostream>

using namespace std;

int main() {
  string x;
  while (cin >> x) {
    if (x == "END") {
      break;
    }
    int l = x.length();
    if (l == 1) {
      if (x == "1") {
        cout << 1;
      }
      else {
        cout << 2;
      }
    }
    else if (l > 1 && l < 10) {
      cout << 3;
    }
    else {
      cout << 4;
    }
    cout << "\n";
  }
  return 0;
}