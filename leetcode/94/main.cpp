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
  vector<int> inorderTraversal(TreeNode* root) {
    if (!root) return vector<int>();
    vector<int> res;
    stack<TreeNode*> stack;
    stack.push(root);
    while (!stack.empty()) {
      TreeNode* node = stack.top();
      if (!node->left && !node->right) {
        res.push_back(node->val);
        stack.pop();
      }
      else {
        if (node->left) {
          stack.push(node->left);
          node->left = nullptr;
        }
        else {
          res.push_back(node->val);
          stack.pop();
          stack.push(node->right);
          node->right = nullptr;
        }
      }
    }
    return res;
  }
};

// class Solution {
// public:
//   vector<int> inorderTraversal(TreeNode* root) {
//     if (!root) return vector<int>();
//     vector<int> res;
//     stack<TreeNode*> stack;
//     TreeNode* curr = root;
//     while (curr || !stack.empty()) {
//       while (curr) {
//         stack.push(curr);
//         curr = curr->left;
//       }
//       curr = stack.top();
//       stack.pop();
//       res.push_back(curr->val);
//       curr = curr->right;
//     }
//     return res;
//   }
// };