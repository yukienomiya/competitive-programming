#include <iostream>

using namespace std;

int main() {
  int n, x, balance;
  int count = 0;
  while (true) {
    cin >> n;
    if (n == 0) break;
    balance = 0;
    while (n--) {
      cin >> x;
      if (x > 0) {
        balance++;
      }
      else {
        balance--;
      }
    }
    count++;
    cout << "Case " << count << ": " << balance << "\n";
  }
  return 0;
}