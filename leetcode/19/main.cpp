using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
  ListNode* removeNthFromEnd(ListNode* head, int n) {
    if (head -> next == nullptr) return nullptr;
    ListNode *v_slow = head, *fast = head;
    int slow_idx = 0, fast_idx = 0;
    while (fast -> next) {
      if (fast_idx - slow_idx == n - 1) {
        slow_idx++;
        if (slow_idx > 1) v_slow = v_slow -> next;
      }
      fast = fast -> next;
      fast_idx++;
    }
    if (slow_idx == 0) return head -> next;
    v_slow -> next = v_slow -> next -> next;
    return head;
  }
};