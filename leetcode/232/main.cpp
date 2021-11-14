#include <stack>

using namespace std;

class MyQueue {
  stack<int> first_on_top, last_on_top;
public:
  MyQueue() {
    stack<int> first_on_top();
    stack<int> last_on_top();
  }
  
  void push(int x) {
    last_on_top.push(x);
  }
  
  int pop() {
    int first = peek();
    first_on_top.pop();
    return first;
  }
  
  int peek() {
    if (first_on_top.empty()) {
      while (!last_on_top.empty()) {
        first_on_top.push(last_on_top.top());
        last_on_top.pop();
      }
    }
    return first_on_top.top();
  }
  
  bool empty() {
    return first_on_top.empty() && last_on_top.empty();
  }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */