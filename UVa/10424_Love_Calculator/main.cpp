#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

float get_name_tot(string name) {
  int value = 0;
  int len = name.length();
  for (int i = 0; i < len; i++) {
    int letter = (int) name[i];
    if (letter >= 65 && letter <= 90) {
      value += letter - 65 + 1;
    }
    else if (letter >= 97 && letter <= 122) {
      value += letter - 97 + 1;
    }
  }
  while (value >= 10) {
    string s = to_string(value);
    value = 0;
    for (int i = 0; i < s.length(); i++) {
      value += s[i] - '0';
    }
  }
  return (float)value;
}

int main() {
  string name1, name2;
  float no1, no2, res;
  while (getline(cin, name1)) {
    getline(cin, name2);
    no1 = get_name_tot(name1);
    no2 = get_name_tot(name2);
    if (no1 == 0.0 && no2 == 0.0) {
      cout << "0.00 %" << "\n";
      continue;
    }
    if (no1 < no2) {
      res = (no1 / no2) * 100;
    }
    else {
      res = (no2 / no1) * 100;
    }
    cout << setprecision(2) << fixed << res << " %" << "\n";
  }
  return 0;
}