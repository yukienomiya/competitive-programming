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
  ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
    ListNode dummy = ListNode(0);
    ListNode* tmp = &dummy;
    while (l1 && l2) {
      if (l1->val < l2->val) {
        tmp->next = l1;
        l1->next = l1;
      }
      else {
        tmp->next = l2;
        l2->next = l2;
      }
    }
    tmp->next = l1 ? l1 : l2;
    return dummy.next;
  }
};