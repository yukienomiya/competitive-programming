#include <vector>
#include <bitset>
#include <iostream>

using namespace std;

class Solution {
public:
  vector<vector<int> > permute(vector<int> &num) {
    vector<vector<int> > result;
    permuteRecursive(num, 0, result);
    return result;
  }

  void permuteRecursive(vector<int> &num, int begin, vector<vector<int> > &result)	{
    if (begin >= num.size()) {
      result.push_back(num);
      return;
    }
		for (int i = begin; i < num.size(); i++) {
      swap(num[begin], num[i]);
      permuteRecursive(num, begin + 1, result);
      swap(num[begin], num[i]);
		}
  }
};

// class Solution {
// public:
//   vector<vector<int>> permute(vector<int>& nums) {
//     vector<vector<int>> sol = {};
//     bitset<6> elems;
//     vector<int> perm;
//     makePerm(sol, elems, perm, nums);
//     return sol;
//   }

//   vector<vector<int>> makePerm(vector<vector<int>>& sol, bitset<6> elems, vector<int> perm, const vector<int>& nums) {
//     if (size(perm) == size(nums)) {
//       sol.push_back(perm);
//     }
//     else {
//       for (int i = 0; i < size(nums); i++) {
//         if (!elems.test(i)) {
//           bitset<6> elems2 = elems;
//           elems2.set(i);
//           vector<int> perm2 = perm;
//           perm2.push_back(nums[i]);
//           makePerm(sol, elems2, perm2, nums);
//         }
//       }
//     }
//     return sol;
//   }
// };