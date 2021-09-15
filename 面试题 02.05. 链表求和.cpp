/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
/**
 下次再刷到的时候用huo的写法更好
 */
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        if(!l1) return l2;
        if(!l2) return l1;
        bool markForward = false;
        ListNode *retNode = l1;
        ListNode *pre = l1;
        while (l1 && l2) {
            l1->val = l1->val + l2->val;
            if(markForward == true) {
                l1->val++;
            }
            if(l1->val >= 10) {
                l1->val = l1->val - 10;
                markForward = true;
            } else {
                markForward = false;
            }
            pre = l1;
            l1 = l1->next;
            l2 = l2->next;
        }
        if (l2) {
            pre->next = l2;
            l1 = pre->next;
            pre = l1;
        }
        while(l1) {
            if (markForward) l1->val++;
            if(l1->val >= 10) {
                l1->val = l1->val - 10;
                markForward = true;
            } else {
                markForward = false;
            }
            pre = l1;
            l1 = l1->next;
        }
        if(markForward){
            pre->next = new ListNode(1);
        }
        return retNode;

    }
};
