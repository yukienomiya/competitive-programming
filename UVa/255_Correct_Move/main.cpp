#include <iostream>
#include <vector>

using namespace std;

bool InTheSameRow(int x1, int x2) {
  int x = x1 % 8;
  int start_row = x1 - x, end_row = x1 + (8 - x - 1);
  return x2 >= start_row && x2 <= end_row;
}

bool InTheSameColumn(int x1, int x2) {
  return x1 % 8 == x2 % 8;
}

bool QMoveIsLegal(int k, int q, int new_q) {
  if (new_q == k || new_q == q) {
    return false;
  }
  int x = q % 8;
  int q1 = min(q, new_q), q2 = max(q, new_q);
  if (InTheSameRow(q, new_q)) {
    if (k > q1 && k < q2) {
      return false;
    }
    return true;
  }
  else if (InTheSameColumn(q, new_q)) {
    if (k % 8 == x && k > q1 && k < q2) {
      return false;
    }
    return true;
  }
  return false;
}

vector<int> GetPossibleKingsMoves(int k) {
  vector<int> allowed_moves;
  if ((k - 1) % 8 != 7) {
    allowed_moves.push_back(k - 1);
  }
  if ((k + 1) % 8 != 0) {
    allowed_moves.push_back(k + 1);
  }
  if ((k - 8) >= 0) {
    allowed_moves.push_back(k - 8);
  }
  if ((k + 8) <= 63) {
    allowed_moves.push_back(k + 8);
  }
  return allowed_moves;
}

bool QMoveIsAllowed(int k, int new_q) {
  vector<int> k_allowed = GetPossibleKingsMoves(k);
  for (auto it = k_allowed.begin(); it != k_allowed.end(); ++it) {
    if (*it == new_q) {
      return false;
    }
  }
  return true;
}

int GetAllowedKingsMoves(int k, int q, int new_q) {
  vector<int> k_allowed = GetPossibleKingsMoves(k);
  int res = 0;
  for (auto it = k_allowed.begin(); it != k_allowed.end(); ++it) {
    if (*it != new_q && *it != q && !InTheSameColumn(*it, new_q) && !InTheSameRow(*it, new_q)) {
      res++;
    }
  }
  return res;
}

int main() {
  int k, q, new_q;
  while (cin >> k >> q >> new_q) {
    if (k == q) {
      cout << "Illegal state";
    }
    else if (!QMoveIsLegal(k, q, new_q)) {
      cout << "Illegal move";
    }
    else if (!QMoveIsAllowed(k, new_q)) {
      cout << "Move not allowed";
    }
    else {
      int k_allowed_moves = GetAllowedKingsMoves(k, q, new_q);
      if (k_allowed_moves > 0) {
        cout << "Continue";
      }
      else {
        cout << "Stop";
      }
    }
    cout << endl;
  }
  return 0;
}