#include <iostream>
#include <string>
#include <deque>

using namespace std;

int main() {
  int cases;
  cin >> cases;
  cin.ignore();
  string universe;
  while (cases--) {
    getline(cin, universe);
    deque<int> levels;
    int tot = 0;
    int lev = 0;
    int l = universe.length();
    for (int i = 0; i < l; i++) {
      char ch = universe[i];
      if (ch == '\\') {
        lev--;
        levels.push_back(i);
      }
      else if (ch == '/') {
        if (lev < 0) {
          lev++;
          int starting_point = levels.back();
          levels.pop_back();
          tot += i - starting_point;
        }
      }
    }
    cout << tot << "\n";
  }
  return 0;
}