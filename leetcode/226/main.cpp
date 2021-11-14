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
  TreeNode* invertTree(TreeNode* root) {
    if (!root) return root;
    stack<TreeNode*> stack;
    stack.push(root);
    while (!stack.empty()) {
      TreeNode* node = stack.top();
      stack.pop();
      if (node) {
        stack.push(node->left);
        stack.push(node->right);
        swap(node->left, node->right);
      }
    }
    return root;
  }
};