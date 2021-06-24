#include <iostream>
#include <string>

using namespace std;

int main() {
  int cases;
  cin >> cases;
  for (int i = 0; i < cases; i++) {
    string s, t;
    cin >> s >> t;
    int count = 0, zeros = 0, ones = 0, q_mark_one = 0;
    for (int j = 0; j < s.length(); j++) {
      char ch_s = s[j];
      char ch_t = t[j];
      if (ch_s != ch_t) {
        if (ch_s == '0') {
          zeros++;
        }
        else if (ch_s == '1') {
          ones++;
        }
        else {
          if (ch_t == '1') {
            q_mark_one++;
          }
          else {
            count++;
          }
        }
      }
    }
    cout << "Case " << i + 1 << ": ";
    if (ones > 0) {
      if (ones > zeros) {
        ones -= zeros;
        if (ones > q_mark_one) {
          cout << -1 << "\n";
          continue;
        }
        q_mark_one -= ones;
        count += 2 * ones;
      }
      count += zeros + q_mark_one;
    }
    else {
      count += zeros + q_mark_one;
    }
    cout << count << "\n";
  }
  return 0;
}