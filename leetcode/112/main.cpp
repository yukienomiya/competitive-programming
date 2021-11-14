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
  bool b(TreeNode* root, const int& targetSum, int tot) {
    if (!root->left && !root->right && tot + root->val == targetSum) return true;
    bool left = false, right = false;
    if (root->left) left = b(root->left, targetSum, tot + root->val);
    if (root->right) right = b(root->right, targetSum, tot + root->val);
    return left || right;
  }

  bool hasPathSum(TreeNode* root, int targetSum) {
    if (!root) return false;
    return b(root, targetSum, 0);
  }
};