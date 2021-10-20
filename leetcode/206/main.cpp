
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
  ListNode* reverseList(ListNode* head) {
    ListNode zero = ListNode(0, head), *one = head;
    while (one && one->next) {
      ListNode* temp = zero.next;
      zero.next = one->next;
      one->next = zero.next->next;
      zero.next->next = temp;
    }
    return zero.next;
  }
};