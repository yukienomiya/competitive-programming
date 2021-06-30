#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

int main() {
  int l;
  while (cin >> l) {
    if (l == 0) {
      break;
    }
    string bend, cur_direction = "+x";
    unordered_map<string, unordered_map<string, string> > bends;
    bends["+x"]["+y"] = "+y";
    bends["+x"]["-y"] = "-y";
    bends["+x"]["+z"] = "+z";
    bends["+x"]["-z"] = "-z";

    bends["-x"]["+y"] = "-y";
    bends["-x"]["-y"] = "+y";
    bends["-x"]["+z"] = "-z";
    bends["-x"]["-z"] = "+z";

    bends["+y"]["+y"] = "-x";
    bends["+y"]["-y"] = "+x";
    bends["+y"]["+z"] = "+y";
    bends["+y"]["-z"] = "+y";

    bends["-y"]["+y"] = "+x";
    bends["-y"]["-y"] = "-x";
    bends["-y"]["+z"] = "-y";
    bends["-y"]["-z"] = "-y";

    bends["+z"]["+y"] = "+z";
    bends["+z"]["-y"] = "+z";
    bends["+z"]["+z"] = "-x";
    bends["+z"]["-z"] = "+x";

    bends["-z"]["+y"] = "-z";
    bends["-z"]["-y"] = "-z";
    bends["-z"]["+z"] = "+x";
    bends["-z"]["-z"] = "-x";

    for (int i = 0; i < l - 1; i++){
      cin >> bend;
      cout << i + 1 << ") " << cur_direction << " - " << bend << endl;
      if (bend == "No") {
        continue;
      }
      else {
        cur_direction = bends[cur_direction][bend];
      }
    }
    cout << cur_direction << endl;
  }
  return 0;
}