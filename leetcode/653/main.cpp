#include <unordered_set>
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
  bool binSearch(TreeNode* root, const TreeNode* node, const int& n) {
    if (!root) return false;
    if (root->val == n && root != node) return true;
    return binSearch(root->left, node, n) || binSearch(root->right, node, n);
  }

  bool findTarget(TreeNode* root, int k) {
    stack<TreeNode*> stack;
    stack.push(root);
    while (!stack.empty()) {
      TreeNode* node = stack.top();
      stack.pop();
      if (binSearch(root, node, k - node->val)) return true;
      if (node->left) stack.push(node->left);
      if (node->right) stack.push(node->right);
    }
    return false;
  }
};

// class Solution {
// public:
//   bool findTarget(TreeNode* root, int k) {
//     unordered_set<int> complements;
//     stack<TreeNode*> stack;
//     stack.push(root);
//     while (!stack.empty()) {
//       TreeNode* node = stack.top();
//       stack.pop();
//       if (complements.find(node->val) != complements.end()) return true;
//       else complements.insert(k - node->val);
//       if (node->left) stack.push(node->left);
//       if (node->right) stack.push(node->right);
//     }
//     return false;
//   }
// };