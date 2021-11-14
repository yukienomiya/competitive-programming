#include <stack>

using namespace std;

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
  bool isSymmetric(TreeNode* root) {
    if (!root->left && !root->right) return true;
    stack<TreeNode*> nodesLeft, nodesRight;
    nodesLeft.push(root->left);
    nodesRight.push(root->right);
    while (!nodesLeft.empty() && !nodesRight.empty()) {
      TreeNode* nodeL = nodesLeft.top();
      TreeNode* nodeR = nodesRight.top();
      nodesLeft.pop();
      nodesRight.pop();
      if (!nodeL && !nodeR) continue;
      if (nodeL && nodeR && nodeL->val == nodeR->val) {
        nodesLeft.push(nodeL->left);
        nodesLeft.push(nodeL->right);
        nodesRight.push(nodeR->right);
        nodesRight.push(nodeR->left);
      }
      else return false;
    }
    return true;
  }
};