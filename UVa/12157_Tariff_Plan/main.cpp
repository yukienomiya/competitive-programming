#include <iostream>
#include <cmath>

using namespace std;

int main() {
  int cases;
  cin >> cases;
  for (int i = 0; i < cases; i++) {
    int calls;
    cin >> calls;
    int mile_price_tot = 0;
    int juice_price_tot = 0;
    for (int j = 0; j < calls; j++) {
      int minutes;
      cin >> minutes;
      if (minutes == 0) {
        continue;
      }
      if (minutes % 30 == 0) {
        mile_price_tot += ((minutes / 30) + 1) * 10;
      }
      else {
        mile_price_tot += int(ceil(minutes / 30.0)) * 10;
      }
      if (minutes % 60 == 0) {
        juice_price_tot += ((minutes / 60) + 1) * 15;
      }
      else {
        juice_price_tot += int(ceil(minutes / 60.0)) * 15;
      }
    }
    cout << "Case " << i + 1 << ": ";
    if (mile_price_tot == juice_price_tot) {
      cout << "Mile Juice " << mile_price_tot;
    }
    else if (mile_price_tot < juice_price_tot) {
      cout << "Mile " << mile_price_tot;
    }
    else {
      cout << "Juice " << juice_price_tot;
    }
    cout << "\n";
  }
  return 0;
}