#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

int main() {
  int p, a, b, c, d, n;
  while (cin >> p >> a >> b >> c >> d >> n) {
    double max_price = 0.0, max_decline = 0.0;
    for (int x = 1; x <= n; x++) {
      double price = p * (sin((a * x) + b) + cos((c * x) + d) + 2);
      double decline = max_price - price;
      if (decline < 0) {
        max_price = price;
      }
      else if (decline > max_decline) {
        max_decline = decline;
      }
    }
    cout << setprecision(12) << max_decline << endl;
  }
  return 0;
}