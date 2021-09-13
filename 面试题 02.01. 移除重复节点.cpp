/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
/**
 数组标记出现过的元素，
 遍历链表，只记录第一次出现的，后面出现的都将其从链表删除
 */
class Solution {
public:
    ListNode* removeDuplicateNodes(ListNode* head) {
        if(!head || !head->next) return head;
        int helper[20001];
        memset(&helper,0,sizeof(helper));
        ListNode *newHead = head;
        while(head) {
            if(helper[head->val] == 0) {
                helper[head->val]++;
            }
            head = head->next;
        }
        ListNode *retHead = newHead;
        ListNode *preNode = newHead;
        while(newHead) {
            if(helper[newHead->val] == 1) {
                helper[newHead->val]--;
                preNode = newHead;
                newHead = newHead->next;
            } else {
                newHead = newHead->next;
                preNode->next = newHead;
            }

        }
        return retHead;
    }
};
