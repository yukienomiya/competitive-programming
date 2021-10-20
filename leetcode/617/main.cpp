#include <vector>
#include <queue>

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
    TreeNode* mergeTrees(TreeNode* root1, TreeNode* root2) {
      if (!root1 || !root2) return root1 ? root1 : root2;
      deque<pair<TreeNode*, TreeNode*>> stack;
      stack.push_back({root1, root2});
      while (!stack.empty()) {
        pair<TreeNode*, TreeNode*> nodes = stack.front();
        stack.pop_front();
        if (!nodes.first || !nodes.second) continue;
        nodes.first->val += nodes.second->val;

        if (!nodes.first->left) nodes.first->left = nodes.second->left;
        else stack.push_back({nodes.first->left, nodes.second->left});
        if (!nodes.first->right) nodes.first->right = nodes.second->right;
        else stack.push_back({nodes.first->right, nodes.second->right});
      }
      return root1;
    }
};