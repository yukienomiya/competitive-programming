#include <iostream>
#include <vector>
#include <utility>
#include <string>

using namespace std;

vector< pair<int, int> > ComputeFramesIntervals(const vector<char>& game) {
  vector< pair<int, int> > intervals;
  int frames = 0, end = 0;
  while (end < game.size()) {
    const int begin = end;
    if (++frames == 10) end = game.size();
    else if (game[begin] == 'X') end += 1;
    else end += 2;
    pair<int, int> f = {begin, end};
    intervals.push_back(f);
  }
  return intervals;
}

int GetScore(const char c) {
  if (c == '/' || c == 'X') return 10;
  return c - '0';
}

int GetScoreForRolls(const vector<char>& game, const int start, const int end) {
  int score = 0;
  for (int i = end - 1; i >= start; --i) {
    score += GetScore(game[i]);
    if (game[i] == '/') i--;
  }
  return score;
}

vector<char> InputScores(string& round) {
  vector<char> game;
  for (char c : round) {
    if (c != ' ') {
      game.push_back(c);
    }
  }
  return game;
}

int CalculateTotalScore(const vector<char>& game) {
  int sol = 0;
  const vector< pair<int, int> > frames = ComputeFramesIntervals(game);
  for (const pair<int, int>& frame : frames) {
    sol += GetScoreForRolls(game, frame.first, frame.second);
    if (frame.second != game.size()) {
      if (game[frame.first] == 'X') {
        sol += GetScoreForRolls(game, frame.second, frame.second + 2);
      } else if (game[frame.first + 1] == '/') {
        sol += GetScoreForRolls(game, frame.second, frame.second + 1);
      }
    }
  }
  return sol;
}

int main() {
  while (true) {
    string round;
    getline(cin, round);
    if (round == "Game Over") {
      break;
    }
    vector<char> game = InputScores(round);
    cout << CalculateTotalScore(game) << endl;
  }
  return 0;
}