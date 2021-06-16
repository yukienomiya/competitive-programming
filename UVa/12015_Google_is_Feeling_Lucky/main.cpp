#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main() {
  int cases;
  cin >> cases;
  for (int count = 0; count < cases; count++) {
    int max_val = 0;
    vector<string> max_urls;
    for (int i = 0; i < 10; i++) {
      string url;
      int val;
      cin >> url >> val;
      if (val > max_val) {
        max_val = val;
        max_urls.clear();
        max_urls.push_back(url);
      }
      else if (val == max_val) {
        max_urls.push_back(url);
      }
    }
    cout << "Case #" << count + 1 << ":\n";
    for (int i = 0; i < max_urls.size(); i++) {
      cout << max_urls[i] << "\n";
    }
  }
  return 0;
}