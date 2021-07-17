#include <iostream>
#include <vector>
#include <utility>
#include <string>

using namespace std;

struct LineFormation {
  vector<pair<int, int>> formation;
};

void MakeFormation(LineFormation& f, int s) {
  f.formation.push_back({0, 0});
  for (int i = 1; i <= s; i++) {
    pair<int, int> soldier = {i - 1, (i + 1) % (s + 1)};
    f.formation.push_back(soldier);
  }
  f.formation.push_back({0, 0});
}

string GetBuddies(LineFormation& f, int d1, int d2) {
  int budL = f.formation[d1].first;
  int budR = f.formation[d2].second;
  f.formation[budL].second = budR;
  f.formation[budR].first = budL;
  string new_bud1 = (budL != 0) ? to_string(budL) : "*";
  string new_bud2 = (budR != 0) ? to_string(budR) : "*";
  return new_bud1 + " " + new_bud2;
}

int main() {
  int no_soldiers, deaths;
  while (cin >> no_soldiers >> deaths) {
    if (no_soldiers == 0 && deaths == 0) break;
    LineFormation f;
    MakeFormation(f, no_soldiers);
    for (int i = 0; i < deaths; i++) {
      int d1, d2;
      cin >> d1 >> d2;
      cout << GetBuddies(f, d1, d2) << endl;
    }
    cout << '-' << endl;
  }
  return 0;
}