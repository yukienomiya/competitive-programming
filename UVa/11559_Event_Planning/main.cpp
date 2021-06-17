#include <iostream>

using namespace std;

int main() {
  int no_people, budget, no_hotels, weeks;
  while(cin >> no_people >> budget >> no_hotels >> weeks) {
    int price;
    bool match_found = false;
    int min_cost = 10001;
    while (no_hotels--) {
      bool within_budget = false;
      cin >> price;
      if (price * no_people <= budget) {
        within_budget = true;
      }
      for (int i = 0; i < weeks; i++) {
        int available_beds;
        cin >> available_beds;
        if (within_budget && available_beds >= no_people) {
          match_found = true;
          if (price < min_cost) {
            min_cost = price;
          }
        }
      }
    }
    if (match_found) {
      cout << min_cost * no_people << "\n";
    }
    else {
      cout << "stay home" << "\n";
    }
  }
  return 0;
}