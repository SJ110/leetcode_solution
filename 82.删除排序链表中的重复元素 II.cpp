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
/**
 和两年前的实现不同，之前使用快慢指针，现在使用下标实现
 */
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        if(!head || !head->next) {
            return head;
        }
        ListNode *tmphead = head;
        ListNode *rethead = tmphead;
        ListNode *preNode = tmphead;
        int tmpArray[201] = {0};
        while(head) {
            tmpArray[head->val+100]++;
            head = head->next;
        }
        for (int i = 0;i<201;i++) {
            if(tmpArray[i] == 1) {
                tmphead->val = i-100;
                preNode = tmphead;
                tmphead = tmphead->next;
            }
        }
        if (tmphead == rethead) {
            return nullptr;
        }
        preNode->next = nullptr;
        return rethead;
    }
};



/// solution two years ago

class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        if(head==NULL ||head->next==NULL) return head;
        ListNode* slow=head;
        ListNode* fst=head->next;
        ListNode* tmp=new ListNode(0);
        ListNode* ret=tmp;
        while(fst){
            if(slow->val==fst->val){
                while(fst && fst->val==slow->val){
                    fst=fst->next;
                }
                slow=fst;
                if(fst) fst=fst->next;
            }else{
           //     cout<<slow->val<<" "<<fst->val<<endl;
                tmp->next=slow;
                tmp=tmp->next;
                slow=slow->next;
                fst=fst->next;
            }
        }
        if(slow && tmp->val!=slow->val){
            tmp->next=slow;
            tmp=tmp->next;
           
        }
        tmp->next=NULL;
        return ret->next;
    }
