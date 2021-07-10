#include <iostream>
#include <string>
#include <vector>

using namespace std;

struct Game {
  int total_score = 0;
  vector<char> scores;
};

int toInt(const char c) {
  if (c == 'X') {
    return 10;
  }
  return c - '0';
}

void InputScores(Game& g, string& round) {
  for (char c : round) {
    if (c != ' ') {
      g.scores.push_back(c);
    }
  }
}

// calculates the simple sum of the next "no_scores" scores starting from the idx + 1 position
int AdditionalRolls(Game& g, int idx, int no_scores) {
  int tot = 0;
  for (int i = 1; i <= no_scores; i++) {
    char next = g.scores[idx + i];
    if (next == 'X') {
      tot += 10;
    }
    else {
      tot += toInt(next);
    }
  }
  return tot;
}

void AddStrike(Game& g, int strike_idx) {
  if (g.scores[strike_idx + 2] == '/') {
    g.total_score += 20;
  }
  else {
    g.total_score += 10 + AdditionalRolls(g, strike_idx, 2);
  }
}

void AddSpare(Game& g, int spare_idx) {
  int x = AdditionalRolls(g, spare_idx, 1);
  g.total_score += 10 + x;
}

int CalculateTotalScore(Game& g) {
  int idx = 0;
  for (int frame = 1; frame < 10; frame++) {
    if (g.scores[idx] == 'X') {
      AddStrike(g, idx);
    }
    else {
      if (g.scores[idx + 1] == '/') {
        AddSpare(g, idx + 1);
      }
      else {
        g.total_score += toInt(g.scores[idx]) + toInt(g.scores[idx + 1]);
      }
      idx++;
    }
    idx++;
  }
  int a = 0;
  if (g.scores[idx] == 'X') {
    if (g.scores[idx + 2] == '/') {
      a += 20;
    }
    else {
      a += 10 + toInt(g.scores[idx + 1]) + toInt(g.scores[idx + 2]);
    }
  }
  else if (g.scores[idx + 1] == '/') {
    a += 10 + toInt(g.scores[idx + 2]);
  }
  else {
    a += toInt(g.scores[idx]) + toInt(g.scores[idx + 1]);
  }
  return g.total_score + a;
}

int main() {
  while (true) {
    string round;
    getline(cin, round);
    if (round == "Game Over") {
      break;
    }
    Game g;
    InputScores(g, round);
    cout << CalculateTotalScore(g) << endl;
  }
  return 0;
}