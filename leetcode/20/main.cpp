#include <string>
#include <stack>

using namespace std;

class Solution {
public:
  bool isValid(string s) {
    stack<char> stack;
    for (char parenthesis : s) {
      if (parenthesis == '(' || parenthesis == '[' || parenthesis == '{') {
        stack.push(parenthesis);
      }
      else {
        if (parenthesis == ')' && !stack.empty() && stack.top() == '(') stack.pop();
        else if (parenthesis == ']' && !stack.empty() && stack.top() == '[') stack.pop();
        else if (parenthesis == '}' && !stack.empty() && stack.top() == '{') stack.pop();
        else return false;
      }
    }
    return stack.empty();
  }
};