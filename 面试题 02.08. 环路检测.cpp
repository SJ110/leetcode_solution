/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
/**
 set查找是否存在，
 快慢指针似乎永远在交叉点相遇，但是我没有证明
 */
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        set<ListNode *>listHlper;
        while(head) {
            if(listHlper.count(head) == 1) {
                return head;
            }
            listHlper.insert(head);
            head = head->next;
        }
        return NULL;
    }
};
