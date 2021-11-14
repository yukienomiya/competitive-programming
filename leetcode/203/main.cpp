struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};
class Solution {
public:
  ListNode* removeElements(ListNode* head, int val) {
    while (head && head->val == val) head = head->next;
    ListNode dummy = ListNode(0, head);
    ListNode* slow = head;
    if (head) head = head->next;
    while (head) {
      if (head->val == val) {
        if (head->next) slow->next = head->next;
        else slow->next = nullptr;
      }
      else slow = slow->next;
      head = head->next;
    }
    return dummy.next;
  }
};