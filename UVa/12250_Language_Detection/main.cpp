#include <iostream>
#include <string>

using namespace std;

int main() {
  string s;
  bool a = true;
  int count = 0;
  while (a) {
    cin >> s;
    count++;
    if (s == "#") {
      a = false;
    }
    else if (s == "HELLO") {
      cout << "Case " << count << ": ENGLISH\n";
    }
    else if (s == "HOLA") {
      cout << "Case " << count << ": SPANISH\n";
    }
    else if (s == "HALLO") {
      cout << "Case " << count << ": GERMAN\n";
    }
    else if (s == "BONJOUR") {
      cout << "Case " << count << ": FRENCH\n";
    }
    else if (s == "CIAO") {
      cout << "Case " << count << ": ITALIAN\n";
    }
    else if (s == "ZDRAVSTVUJTE") {
      cout << "Case " << count << ": RUSSIAN\n";
    }
    else {
      cout << "Case " << count << ": UNKNOWN\n";
    }
  }
  return 0;
}