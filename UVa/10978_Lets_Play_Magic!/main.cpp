#include <iostream>
#include <vector>
#include <string>

using namespace std;

// returns a mod n
int mod(int a, int n) {
  if (a > 0) return a % n;
  return a + n;
}

int main() {
  int n;
  while (cin >> n) {
    if (n == 0) break;
    vector<string> cards;
    for (int i = 0; i < n; i++) {
      cards.push_back("");
    }
    int idx = 0;
    string card, word;
    for (int i = 0; i < n; i++) {
      int begin = idx;
      cin >> card >> word;
      int j = 0;
      while (true) {
        if (cards[idx].length() == 0) {
          j++;
          if (j == word.length()) break;
        }
        idx = mod(idx + 1, n);
      }
      cards[idx] = card;
    }
    for (int i = 0; i < n - 1; i++) {
      cout << cards[i] << " ";
    }
    cout << cards[n - 1] << endl;
  }
  return 0;
}