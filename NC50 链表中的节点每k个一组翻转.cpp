/**
 * struct ListNode {
 *    int val;
 *    struct ListNode *next;
 * };
 */

class Solution {
public:
    /**
     *
     * @param head ListNode类
     * @param k int整型
     * @return ListNode类
     */
    /*
     使用栈来处理o(kn)
     */
    ListNode* reverseKGroup(ListNode* head, int k) {
        // write code here
        if(k == 1 || !head) return head;
        stack<ListNode *>helper;
        ListNode *tmpHead = new ListNode(0);
        ListNode *newHead = tmpHead;
        ListNode *tmpNode = nullptr;
        int cnt = 1;
        while(head) {
            if(cnt<=k) {
                cnt++;
                helper.push(head);
                head = head->next;
            }
            if(cnt > k) {
                cnt = 1;
                while(!helper.empty()) {
                    tmpNode = helper.top();
                    helper.pop();
                    tmpNode->next = nullptr;
                    tmpHead->next = tmpNode;
                    tmpHead = tmpHead->next;
                }
            }
        }
        ListNode *stackBottomNode = nullptr;
        while(!helper.empty()) {
            stackBottomNode = helper.top();
            helper.pop();
        }
        tmpHead->next = stackBottomNode;
        return newHead->next;
    }
};
