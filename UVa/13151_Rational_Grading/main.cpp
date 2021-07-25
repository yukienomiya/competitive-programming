#include <iostream>
#include <string>
#include <unordered_map>
#include <utility>

using namespace std;

int main() {
  cin.unsetf(ios::dec);
  cin.unsetf(ios::hex);
  cin.unsetf(ios::oct);

  unordered_map<string, pair<int, int> > instructions;
  instructions["i"] = {0, 0};
  instructions["i++"] = {0, 1};
  instructions["++i"] = {1, 0};
  instructions["i--"] = {0, -1};
  instructions["--i"] = {-1, 0};

  int value, no_instructions, student_value;

  while (cin >> value >> no_instructions) {
    if (value == 0 && no_instructions == 0) break;
    string instr;
    int score = 0;
    for (int i = 0; i < no_instructions; i++) {
      cin >> instr >> student_value;
      int val_before = value + instructions[instr].first;
      int val_after = val_before + instructions[instr].second;
      if (student_value == val_before) {
        score++;
        value = val_after;
      }
      else value = student_value + instructions[instr].second;
    }
    cout << score << endl;
  }
  return 0;
}