#include <iostream>
#include <string>

using namespace std;

int main() {
  string res = "";
  string n, row1, row2, row3, row4, row5;
  getline(cin, n);
  getline(cin, row1);
  getline(cin, row2);
  getline(cin, row3);
  getline(cin, row4);
  getline(cin, row5);
  string ch_row1, ch_row2, ch_row3, ch_row4, ch_row5;
  for (int i = 0; i < 4 * stoi(n); i += 4) {
    ch_row1 = row1.substr(i, 4);
    ch_row2 = row2.substr(i, 4);
    ch_row3 = row3.substr(i, 4);
    ch_row4 = row4.substr(i, 4);
    ch_row5 = row5.substr(i, 4);
    if (ch_row1 == ".*.." && ch_row1 == ch_row2 && ch_row1 == ch_row3 && ch_row1 == ch_row4 && ch_row1 == ch_row5) {
      res += '1';
    }
    else if (ch_row1 == "***." && ch_row3 == ch_row1 && ch_row5 == ch_row1 && ch_row2 == "..*.") {
      if (ch_row4 == "*...") {
        res += '2';
      }
      else if (ch_row4 == "..*.") {
        res += '3';
      }
    }
    ch_row1 = "", ch_row2 = "", ch_row3 = "", ch_row4 = "", ch_row5 = "";
  }
  cout << res << "\n";
  return 0;
}