#include <iostream>
#include <string>
#include <vector>

using namespace std;

struct Deck {
  // we'll use these vectors as stacks
  vector<char> faceup;
  vector<char> facedown;
};

void InsertFacedown(Deck& d, const string& cards) {
  for (auto it = cards.rbegin(); it != cards.rend(); ++it) {
    d.facedown.push_back(*it);
  }
}

void DrawCard(Deck& d) {
  if (d.facedown.empty()) {
    for (auto it = d.faceup.rbegin(); it != d.faceup.rend(); ++it) {
      d.facedown.push_back(*it);
    }
    d.faceup.clear();
  }
  d.faceup.push_back(d.facedown.back());
  d.facedown.pop_back();
}

bool IsSnap(const Deck& d1, const Deck& d2) {
  return d1.faceup.back() == d2.faceup.back();
}

bool IsWinningCondition(const Deck& d1, const Deck& d2, int winner) {
  const Deck& ld = winner == 0 ? d2 : d1;
  return ld.facedown.empty() && ld.faceup.empty();
}

void DoSnap(Deck& d1, Deck& d2, int winner) {
  Deck& wd = winner == 0 ? d1 : d2;
  Deck& ld = winner == 0 ? d2 : d1;
  for (char c : ld.faceup) {
    wd.faceup.push_back(c);
  }
  ld.faceup.clear();
}

void PrintSnap(Deck& d1, Deck& d2, int winner) {
  string w_name = winner == 0 ? "Jane" : "John";
  Deck &wd = winner == 0 ? d1 : d2;
  cout << "Snap! for " << w_name << ": ";
  for (auto it = wd.faceup.rbegin(); it != wd.faceup.rend(); ++it) {
    cout << *it;
  }
  cout << endl;
}

void PrintWinner(int winner) {
  string w_name = winner == 0 ? "Jane" : "John";
  cout << w_name << " wins." << endl;
}

int main() {
  int cases;
  cin >> cases;
  cin.ignore();
  for (int i = 0; i < cases; i++) {
    Deck d1, d2;
    string blank, d1_s, d2_s;
    getline(cin, blank);
    getline(cin, d1_s);
    getline(cin, d2_s);
    InsertFacedown(d1, d1_s);
    InsertFacedown(d2, d2_s);
    int n = 1000;
    while (n--) {
      DrawCard(d1);
      DrawCard(d2);
      if (IsSnap(d1, d2)) {
        int winner = (random() / 141) % 2;
        DoSnap(d1, d2, winner);
        PrintSnap(d1, d2, winner);
        if (IsWinningCondition(d1, d2, winner)) {
          PrintWinner(winner);
          break;
        }
      }
      if (n == 0) {
        cout << "Keeps going and going ..." << endl;
      }
    }
    if (i < cases - 1) {
      cout << endl;
    }
  }
  return 0;
}