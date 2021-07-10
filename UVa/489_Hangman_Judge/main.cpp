#include <iostream>
#include <set>
#include <string>

using namespace std;

string RemoveDupes(string s) {
  string new_s = "";
  for (char c : s) {
    bool isDupe = false;
    for (char c2 : new_s) {
      if (c == c2) {
        isDupe = true;
        break;
      }
    }
    if (!isDupe) {
      new_s += c;
    }
  }
  return new_s;
}

int main() {
  int n;
  string s;
  while (true) {
    getline(cin, s);
    n = stoi(s);
    if (n == -1) {
      break;
    }
    set<char> answer_letters;
    string ans, guesses;
    int wrong_guesses = 0;
    getline(cin, ans);
    for (char c : ans) {
      answer_letters.insert(c);
    }
    getline(cin, guesses);
    guesses = RemoveDupes(guesses);
    for (char c : guesses) {
      if (answer_letters.empty() || wrong_guesses >= 7) {
        break;
      }
      if (answer_letters.find(c) != answer_letters.end()) {
        answer_letters.erase(c);
      }
      else {
        wrong_guesses++;
      }
    }
    cout << "Round " << n << endl;
    if (wrong_guesses >= 7) {
      cout << "You lose." << endl;
    }
    else if (answer_letters.empty()) {
      cout << "You win." << endl;
    }
    else {
      cout << "You chickened out." << endl;
    }
  }
  return 0;
}