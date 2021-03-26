/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        if(!head || !head->next) {
            return head;
        }
        ListNode *tmphead = head;
        ListNode *rethead = tmphead;
        ListNode *preNode = tmphead;
        int tmpArray[201] = {0};
        while(head) {
            tmpArray[head->val+100]++;
            head = head->next;
        }
        for (int i = 0;i<201;i++) {
            if(tmpArray[i] >= 1) {
                tmphead->val = i-100;
                preNode = tmphead;
                tmphead = tmphead->next;
            }
        }
        preNode->next = nullptr;
        return rethead;
    }
};
