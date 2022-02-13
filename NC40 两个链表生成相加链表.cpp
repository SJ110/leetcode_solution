/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

class Solution {
public:
    /**
     *
     * @param head1 ListNode类
     * @param head2 ListNode类
     * @return ListNode类
     */
    ListNode* addInList(ListNode* head1, ListNode* head2) {
        // write code here
        ListNode *newHead1 = revertList(head1);
        ListNode *newHead2 = revertList(head2);
        ListNode *retNode = new ListNode(0);
        ListNode *tmp = retNode;
        int forWard = 0;
        while (newHead1 || newHead2) {
            int num1 = 0,num2 = 0;
            if(newHead1) {
                num1 = newHead1->val;
                newHead1 = newHead1->next;
            }
            if(newHead2) {
                num2 = newHead2->val;
                newHead2 = newHead2->next;
            }
            if(num1+num2+forWard >= 10) {
                retNode->val = num1+num2+forWard-10;
                forWard = 1;
            } else {
                retNode->val = num1+num2+forWard;
                forWard = 0;
            }
            retNode->next = new ListNode(0);
            retNode = retNode->next;
        }
        if(forWard == 1) {
            retNode->val = 1;
        } else {
            retNode = nullptr;
        }
        tmp = revertList(tmp);
        if (tmp->val == 0) {
            return tmp->next;
        }
        return tmp;
    }
    
    ListNode *revertList(ListNode *head) {
        ListNode *pre = nullptr;
        ListNode *now = head;
        while(now) {
            ListNode *tmp = now;
            now = now->next;
            tmp->next = pre;
            pre = tmp;
        }
        head = pre;
        return head;
    }
};
