struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
  ListNode* deleteDuplicates(ListNode* head) {
    ListNode zero = ListNode(0, head);
    ListNode* cur;
    int value;
    while (head) {
      value = head->val;
      cur = head->next;
      while (cur && cur->val == value) {
        if (!cur->next) head->next = nullptr;
        else head->next = cur->next;
        cur = cur->next;
      }
      head = cur;
    }
    return zero.next;
  }
};