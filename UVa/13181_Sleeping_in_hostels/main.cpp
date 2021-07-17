#include <iostream>
#include <string>

using namespace std;

int getMaxDistance(string row) {
  int max_distance = 0, count = 0, idx = 0;
  while (idx < row.length()) {
    if (row[idx] == 'X') break;
    else count++;
    idx++;
  }
  max_distance = count - 1;
  count = 0;
  while (idx < row.length()) {
    if (row[idx] == 'X') {
      int dist = (count % 2 == 0) ? (count - 1) / 2 : (count / 2);
      if (dist > max_distance) max_distance = dist;
      count = 0;
    }
    else count++;
    idx++;
  }
  return max(max_distance, count - 1);
}

int main() {
  string row;
  while (getline(cin, row)) {
    cout << getMaxDistance(row) << endl;
  }
  return 0;
}