#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main() {
  int cases;
  cin >> cases;
  for (int i = 0; i < cases; i++) {
    int no_instr;
    cin >> no_instr;
    vector<int> instructions;
    int pos = 0;
    cin.ignore();
    for (int j = 0; j < no_instr; j++) {
      string instr;
      getline(cin, instr);
      if (instr == "LEFT") {
        pos += -1;
        instructions.push_back(-1);
      }
      else if (instr == "RIGHT") {
        pos += 1;
        instructions.push_back(1);
      }
      else {
        string num = "";
        for (int k = instr.length() - 1; k > 0; k--) {
          if (instr[k] == ' ') {
            break;
          }
          num = instr[k] + num;
        }
        int referenced_instr_no = stoi(num);
        int referenced_instr = instructions[referenced_instr_no - 1];
        pos += referenced_instr;
        instructions.push_back(referenced_instr);
      }
    }
    cout << to_string(pos) << "\n";
  }
  return 0;
}