#include <iostream>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  int N, first, second;
  while (cin >> N >> first >> second) {
    int no_players = 1 << N;
    first += no_players - 1;
    second += no_players - 1;
    for (int i = 0; i < N; i++) {
      first /= 2;
      second /= 2;
      if (first == second) {
        cout << i + 1 << "\n";
        break;
      }
    }
  }
  return 0;
}