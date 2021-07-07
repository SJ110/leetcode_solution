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
 关键是指出什么指针结束的时候。
 交换逻辑其实比较简单
 */
class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        if(head == nullptr || head->next == nullptr) {
            return head;
        }
        ListNode* second = head->next;
        ListNode* first = head;
        ListNode* last = second;
        ListNode* retNode = second;
        int flag = 1;
        while(last) {
            ListNode* tmp;
            if(first == head && flag == 1) {
                first->next = second->next;
                second->next = first;
                tmp = first;
            } else {
                swapNode(first,second,last);
                tmp = second;
            }
            if(tmp->next) {
                first = tmp;
                second = tmp->next;
                last = tmp->next->next;
                flag = 0;
            }else{
                break;
            }
        }
        return retNode;
    }

private:
    void swapNode(ListNode* first, ListNode* second, ListNode* last) {
        first->next = last;
        second->next = last->next;
        last->next = second;
    }
};
