#include <iostream>
#include <string>

using namespace std;

int main() {
  int value;
  while (cin >> value) {
    if (value == 0) break;
    while (value >= 10) {
      string s = to_string(value);
      value = 0;
      for (int i = 0; i < s.length(); i++) {
        value += s[i] - '0';
      }
    }
    cout << value << "\n";
  }
  return 0;
}