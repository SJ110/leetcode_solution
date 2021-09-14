/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
 //评论区给出的方法是快指针先走k步，慢指针在出发，直到末尾时，慢指针即为所得
class Solution {
public:
    int kthToLast(ListNode* head, int k) {
        vector<int> listNodeHelper;
        while(head) {
            listNodeHelper.push_back(head->val);
            head = head->next;
        }
        return listNodeHelper[listNodeHelper.size() - k];
    }
};
