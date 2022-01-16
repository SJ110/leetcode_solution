/*
struct ListNode {
    int val;
    struct ListNode *next;
    ListNode(int x) :
            val(x), next(NULL) {
    }
};*/
class Solution {
public:
    ListNode* ReverseList(ListNode* pHead) {
        if(!pHead) return pHead;
//         ListNode *tail = nullptr;
        ListNode *head = pHead->next;
        pHead->next = nullptr;
        ListNode *tmp = head;
        while(head) {
            head = head->next;
            tmp->next = pHead;
            pHead = tmp;
            tmp = head;
        }
        return pHead;
    }
};
