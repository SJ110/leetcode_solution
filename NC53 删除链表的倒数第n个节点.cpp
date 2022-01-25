/**
 * struct ListNode {
 *    int val;
 *    struct ListNode *next;
 * };
 */

class Solution {
public:
    /**
     *
     * @param head ListNode类
     * @param n int整型
     * @return ListNode类
     */
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        // write code here
        ListNode *newHead = new ListNode(0);
        newHead->next = head;
        ListNode *fast = newHead;
        ListNode *slow = newHead;
        int i = 0;
        while(i<n) {
            fast = fast->next;
            i++;
        }
        while(fast->next) {
            fast = fast->next;
            slow = slow->next;
        }
        slow->next = slow->next->next;
        return newHead->next;
    }
};
