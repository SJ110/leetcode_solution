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
    ListNode* Merge(ListNode* pHead1, ListNode* pHead2) {
        if(!pHead1) return pHead2;
        if(!pHead2) return pHead1;
        if(pHead1->val > pHead2->val) {
            swap(pHead1, pHead2);
        }
        
        ListNode *target = pHead1;
        while(pHead1 && pHead2) {
              ListNode *preNode = pHead1;
                while(pHead1 && pHead1->val <= pHead2->val) {
                    preNode = pHead1;
                    pHead1 = pHead1->next;
                }
                ListNode *tmp = pHead2;
                pHead2 = pHead2->next;
                tmp->next = preNode->next;
                preNode->next = tmp;
                pHead1 = tmp;
        }
        return target;
    }
};
