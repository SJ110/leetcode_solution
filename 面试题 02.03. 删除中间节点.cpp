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
    void deleteNode(ListNode* node) {
        // 题目也没说只能访问当前节点呀，这种解法应该是对的。
        // ListNode *pre = node;
        // ListNode *nex = node;
        // while(nex) {
        //     swap(pre->val, nex->val);
        //     pre = nex;
        //     nex = nex->next;
        // }
        // pre = nex;
        node->val = node->next->val;
        node->next = node->next->next;
    }
};
