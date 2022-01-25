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
    ListNode* FindFirstCommonNode( ListNode* pHead1, ListNode* pHead2) {
        int cnt1 = 0,cnt2 = 0;
        ListNode *node1 = pHead1,*node2 = pHead2;
        while (node1) {
            node1 = node1->next;
            cnt1++;
        }
        while (node2) {
            node2 = node2->next;
            cnt2++;
        }
        if(cnt2>cnt1) {
            while(cnt2!=cnt1) {
                pHead2 = pHead2->next;
                cnt2--;
            }
        } else if(cnt2 < cnt1) {
            while (cnt2 != cnt1) {
                pHead1 = pHead1->next;
                cnt1--;
            }
        }
        while(pHead1 != pHead2) {
            pHead1 = pHead1->next;
            pHead2 = pHead2->next;
        }
        return pHead1;
    }
};
