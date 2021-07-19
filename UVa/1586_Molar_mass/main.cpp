#include <iostream>
#include <string>
#include <unordered_map>
#include <iomanip>

using namespace std;

int toInt(const string& str, int begin, int end) {
  int tot = 0, mul = 1;
  for (int i = end - 1; i >= begin; i--) {
    int x = str[i] - '0';
    tot += x * mul;
    mul *= 10;
  }
  return tot;
}

int toInt2(const string& str, int begin, int end) {
  string subs = str.substr(begin, end);
  return stoi(subs);
}

int main() {
  unordered_map<char, float> atomic_weights;
  atomic_weights['C'] = 12.01;
  atomic_weights['H'] = 1.008;
  atomic_weights['O'] = 16.00;
  atomic_weights['N'] = 14.01;

  int cases;
  cin >> cases;
  cin.ignore();
  while (cases--) {
    string formula;
    getline(cin, formula);
    int idx = 0;
    float tot = 0.0;
    while (idx < formula.length() && isalpha(formula[idx])) {
      int begin_idx = idx + 1;
      int end_idx = begin_idx;
      while (end_idx < formula.length() && isdigit(formula[end_idx])) {
        end_idx++;
      }
      int n = ((end_idx - begin_idx) > 0) ? toInt2(formula, begin_idx, end_idx) : 1;
      tot += atomic_weights[formula[idx]] * n;
      idx = end_idx;
    }
    cout << fixed;
    cout << setprecision(3);
    cout << tot << endl;
  }
  return 0;
}