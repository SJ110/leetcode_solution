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

/*
 首先保存首节点，然后计算节点个数，同时首尾相连，在从循环列表中找到新的首节点即可
 */
class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if(head == nullptr) {
            return head;
        }
        ListNode *tmpHead = head;
        int nodeCount = 1;
        while(tmpHead->next){
            nodeCount++;
            tmpHead = tmpHead->next;
        }
        k = k%nodeCount;
        if(k == 0) {
            return head;
        }
        k = nodeCount - k;
        tmpHead->next = head;
        while(k>1) {
            head = head->next;
            k--;
        }
        ListNode *retHead = head->next;
        head->next = nullptr;
        return retHead;
    }
};
