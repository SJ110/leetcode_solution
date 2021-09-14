/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
//找到第一个>=x的节点，使用双指针遍历列表，如果fast的值<x交换slow和fast值。
class Solution {
public:
    ListNode* partition(ListNode* head, int x) {
        ListNode *newhead = head;
        while(head && head->val < x) {
            head = head->next;
        }
        ListNode *slow = head;
        ListNode *fast = head;
        while (fast) {
            if(fast->val < x) {
                swap(fast->val,slow->val);
                slow = slow->next;
                fast = fast->next;
            } else {
                fast = fast->next;
            }
        }
        return newhead;
    }
};
