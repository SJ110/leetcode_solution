/*
struct ListNode {
    int val;
    struct ListNode *next;
    ListNode(int x) :
        val(x), next(NULL) {
    }
};
*/
class Solution {
public:
    ListNode* EntryNodeOfLoop(ListNode* pHead) {
        ListNode *fast = pHead;
        ListNode *slow = pHead;
        ListNode *tmpHead = pHead;
        while (slow && fast) {
            slow = slow->next;
            fast = fast->next;
            if (fast) {
                fast = fast->next;
            }
            if(slow == fast) {
                break;
            }
        }
        if(slow == fast && fast) {
            while(fast != tmpHead) {
                fast = fast->next;
                tmpHead = tmpHead->next;
            }
        }
        return fast;
    }
};
