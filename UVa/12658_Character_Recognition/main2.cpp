#include <iostream>
#include <string>

using namespace std;

int main() {
  string res = "";
  string n, row;
  getline(cin, n);
  for (int i = 0; i < 4; i++) {
    getline(cin, row);
  }
  string ch = "";
  for (int i = 0; i < 4 * stoi(n); i += 4) {
    ch = row.substr(i, 4);
    if (ch == ".*..") {
      res += '1';
    }
    else if (ch == "*...") {
      res += '2';
    }
    else {
      res += '3';
    }
    ch = "";
  }
  cout << res << "\n";
  return 0;
}