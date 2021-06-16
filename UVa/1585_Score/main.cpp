#include <iostream>
#include <string>

using namespace std;

int main() {
  string test_cases;
  getline(cin, test_cases);
  int n = stoi(test_cases);
  string s;
  while (n--) {
    getline(cin, s);
    int l = s.length();
    int o_count = 0;
    int sum = 0;
    for (int i = 0; i < l; i++) {
      if (s[i] == 'O') {
        o_count++;
        sum += o_count;
      }
      else {
        o_count = 0;
      }
    }
    cout << sum << "\n";
  }
  return 0;
}