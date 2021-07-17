#include <iostream>

using namespace std;

int main() {
  int no_cars;
  while (cin >> no_cars) {
    if (no_cars == 0) break;
    int positions[no_cars][2];
    int starting_positions[no_cars] = {0};
    for (int i = 0; i < no_cars; i++) {
      cin >> positions[i][0] >> positions[i][1];
    }
    int error = false;
    for (int i = 0; i < no_cars; i++) {
      int original_pos = i + positions[i][1];
      if (original_pos >= 0 && original_pos < no_cars && starting_positions[original_pos] == 0) {
        starting_positions[original_pos] = positions[i][0];
      }
      else {
        error = true;
        break;
      }
    }
    if (error) cout << -1;
    else {
      for (int i = 0; i < no_cars; i++) {
        cout << starting_positions[i];
        if (i != no_cars - 1) {
          cout << " ";
        }
      }
    }
    cout << endl;
  }
  return 0;
}