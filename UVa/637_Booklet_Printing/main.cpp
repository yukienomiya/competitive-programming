#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
  int no_pages;
  while (cin >> no_pages) {
    if (no_pages == 0) break;
    if (no_pages == 1) {
      cout << "Printing order for 1 pages:" << endl;
      cout << "Sheet 1, front: Blank, 1" << endl;
      continue;
    }
    int blank_pages = (no_pages % 4 != 0) ? (4 - (no_pages % 4)) : 0;
    int total_pages = no_pages + blank_pages;
    vector<string> pages;
    pages.reserve(total_pages);
    for (int i = 0; i < no_pages; i++) {
      pages.push_back(to_string(i + 1));
    }
    for (int i = 0; i < blank_pages; i++) {
      pages.push_back("Blank");
    }
    cout << "Printing order for " << no_pages << " pages:" << endl;
    int sheet = 1, i = 0, j = total_pages - 1;
    int no_sheets = total_pages / 4;
    for (int idx = 0; idx < no_sheets; idx++) {
      string to_print[4] = {pages[j], pages[i], pages[i + 1], pages[j - 1]};
      i += 2;
      j -= 2;
      cout << "Sheet " << idx + 1 << ", front: " << to_print[0] << ", " << to_print[1] << endl;
      cout << "Sheet " << idx + 1 << ", back : " << to_print[2] << ", " << to_print[3] << endl;
    }
  }
  return 0;
}