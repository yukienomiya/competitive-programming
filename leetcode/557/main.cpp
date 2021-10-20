#include <string>
#include <iostream>
#include <cmath>

using namespace std;

string reverseWords(string s) {
  int start = 0, end = 0, j = 0;
  while (end < size(s)) {
    while (end < size(s) && s[end] != ' ') {
      if (end == size(s)) break;
      end++;
    }
    j = end - 1;
    for (int i = start; i < int(floor(start + end) / 2); i++) {
      swap(s[i], s[j--]);
    }
    start = ++end;
  }
  return s;
}

int main() {
  cout << reverseWords("My happy place");
  return 0;
}