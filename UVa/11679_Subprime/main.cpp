#include <iostream>

using namespace std;

int main() {
  int no_banks, no_debentures;
  while (cin >> no_banks >> no_debentures) {
    if (no_banks == 0 && no_debentures == 0) {
      break;
    }
    int reserves[no_banks];
    for (int i = 0; i < no_banks; i++) {
      cin >> reserves[i];
    }
    bool bailout = false;
    for (int i = 0; i < no_debentures; i++) {
      int debtor_bank, creditor_bank, debenture;
      cin >> debtor_bank >> creditor_bank >> debenture;
      reserves[debtor_bank - 1] -= debenture;
      reserves[creditor_bank - 1] += debenture;
    }
    for (int i = 0; i < no_banks; i++) {
      if (reserves[i] < 0) {
        bailout = true;
        break;
      }
    }
    if (bailout) {
      cout << "N" << "\n";
    }
    else {
      cout << "S" << "\n";
    }
  }
  return 0;
}