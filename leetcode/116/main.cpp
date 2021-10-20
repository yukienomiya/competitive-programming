#include <vector>
#include <deque>
#include <iostream>

using namespace std;

class Node {
public:
  int val;
  Node* left;
  Node* right;
  Node* next;

  Node() : val(0), left(nullptr), right(nullptr), next(nullptr) {}

  Node(int _val) : val(_val), left(nullptr), right(nullptr), next(nullptr) {}

  Node(int _val, Node* _left, Node* _right, Node* _next)
      : val(_val), left(_left), right(_right), next(_next) {}
};

class Solution {
public:
  Node* connect(Node* root) {
    vector<Node*> nodes;
    int idx = 0;
    nodes.push_back(root);
    while (true) {
      if (!nodes[idx] -> left) break;
      nodes.push_back(nodes[idx]->left);
      nodes.push_back(nodes[idx]->right);
      idx++;
    }
    
    int no_leaves = 2;
    idx = 1;
    while (idx < size(nodes)) {
      while (idx < idx + no_leaves - 1) {
        nodes[idx] -> next = nodes[++idx];
      }
      no_leaves *= 2;
    }
    return root;
  }
};

int main() {
  Node n7 = Node(7);
  Node n6 = Node(6);
  Node n5 = Node(5);
  Node n4 = Node(4);
  Node n3 = Node(3, &n6, &n7, nullptr);
  Node n2 = Node(2, &n4, &n5, nullptr);
  Node root = Node(1, &n2, &n3, nullptr);

  Solution s;
  s.connect(&root);
  deque<Node*> stack;
  stack.push_back(&root);
  while (!stack.empty()) {
    Node* n = stack.back();
    stack.pop_back();
    cout << n -> val << " - " << n -> next;
    if (!n -> left) break;
    stack.push_back(n->left);
    stack.push_back(n->right);
  }
  return 0;
}