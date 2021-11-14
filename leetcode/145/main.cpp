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
  void dfs(TreeNode* root, vector<int>& result) {
    if (root->left) dfs(root->left, result);
    if (root->right) dfs(root->right, result);
    result.push_back(root->val);
  }

  vector<int> postorderTraversal(TreeNode* root) {
    vector<int> result;
    if (root) dfs(root, result);
    return result;
  }
};

// class Solution {
// public:
//   vector<int> postorderTraversal(TreeNode* root) {
//     vector<int> result;
//     stack<TreeNode*> stack;
//     stack.push(root);
//     while (root && !stack.empty()) {
//       TreeNode* node = stack.top();
//       if (!node->right && !node->left) {
//         result.push_back(node->val);
//         stack.pop();
//       }
//       if (node->right) {
//         stack.push(node->right);
//         node->right = nullptr;
//       }
//       if (node->left) {
//         stack.push(node->left);
//         node->left = nullptr;
//       }
//     }
//     return result;
//   }
// };