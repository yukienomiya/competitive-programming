#include <vector>
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
  vector<int> preorderTraversal(TreeNode* root) {
    if (!root) return vector<int>();
    vector<int> res;
    stack<TreeNode*> stack;
    stack.push(root);
    while (!stack.empty()) {
      TreeNode* node = stack.top();
      res.push_back(node->val);
      stack.pop();
      if (node->right) stack.push(node->right);
      if (node->left) stack.push(node->left);
    }
    return res;
  }
};