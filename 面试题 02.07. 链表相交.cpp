/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
/**
 用栈保存。在pop比较是否有想用的node
 */
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        stack<ListNode *> headAHelper;
        stack<ListNode *> headBHelper;
        while(headA) {
            headAHelper.push(headA);
            headA = headA->next;
        }
        while(headB) {
            headBHelper.push(headB);
            headB = headB->next;
        }
        ListNode *ret = NULL;
        while(!headAHelper.empty() && !headBHelper.empty()) {
            if(headAHelper.top() == headBHelper.top()) {
                ret = headAHelper.top();
                headAHelper.pop();
                headBHelper.pop();
            } else {
                break;
            }
        }
        return ret;
    }
};
