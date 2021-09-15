/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
/**
 使用链表反转要小心点，自己老是转不过去，就用原始办法吧
 */
class Solution {
public:
    bool isPalindrome(ListNode* head) {
        vector<int> ListNodeHelper;
        while(head) {
            ListNodeHelper.push_back(head->val);
            head = head->next;
        }
        int hHead = 0,tail = ListNodeHelper.size()-1;
        while(hHead <= tail) {
            if(ListNodeHelper[hHead++] != ListNodeHelper[tail--])
                return false;
        }
        return true;
    }
};
