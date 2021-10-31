#include <vector>
#include <iostream>
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
  int maximumUnits(vector<vector<int>>& boxTypes, int truckSize) {
    sort(boxTypes.begin(), boxTypes.end(), [](const vector<int> &v1, const vector<int> &v2) { 
      return v1[1] > v2[1];
    });
    int tot = 0, idx = 0, boxes = 0;
    while (idx < size(boxTypes) && boxes < truckSize) {
      if (boxTypes[idx][0] == 0) idx++;
      else {
        tot += boxTypes[idx][1];
        boxTypes[idx][0]--;
        boxes++;
      }
    }
    return tot;
  }
};

int main() {
  Solution s;
  vector<vector<int>> matrix = {{1,3},{2,2},{3,1}};
  cout << s.maximumUnits(matrix, 4);
}