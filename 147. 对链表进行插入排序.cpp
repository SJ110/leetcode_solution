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
class Solution {
public:
    ListNode* insertionSortList(ListNode* head) {
        if(head == nullptr || head->next == nullptr) {
            return head;
        }

        ListNode *ret = head;
        while(head && head->next) {
            if(head->val < head->next->val) {
                head = head->next;
                continue;
            }
            ListNode *tmp = head->next;
            ListNode *tmpNode = head;
            head = head->next;
            ListNode *preNode = ret;
            for(ListNode *idxNode = ret; idxNode != tmp; idxNode = idxNode->next) {
                if(tmp->val < idxNode->val) {
                    /// 比该节点小
                    /// 如果当前节点比首节点小
                    if(ret == idxNode) {
                        /// 取出tmp
                        tmpNode->next = tmp->next;
                        /// tmp插入到首节点前
                        tmp->next = ret;
                        /// tmp作为新的首节点
                        ret = tmp;
                    } else {
                        /// 不是比首节点小
                        /// 取出tmp
                        tmpNode->next = tmp->next;
                        /// 插入tmp
                        preNode->next = tmp;
                        tmp->next = idxNode;
                    }
                    break;
                } else {
                    preNode = idxNode;
                }
            }
        }
        return ret;
    }
};
