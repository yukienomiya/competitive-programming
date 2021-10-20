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
  ListNode* middleNode(ListNode* head) {
    bool m = true;
    ListNode* end = head;
    ListNode* mid = head;
    while (end -> next) {
      if (m) {
        mid = mid -> next;
        m = false;
      }
      else m = true;
      end = end -> next;
    }
    return mid;
  }
};

// leetcode solution:
//
// class Solution {
// public:
//   ListNode* middleNode(ListNode* head) {
//     ListNode* fast = head;
//     ListNode* slow = head;
//     while (fast != nullptr && fast -> next != nullptr) {
//       slow = slow -> next;
//       fast = fast -> next -> next;
//     }
//     return slow;
//   }
// };