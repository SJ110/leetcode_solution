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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if(left == right) {
            return head;
        }

        int i = 1;
        int cache[right - left + 1];
        ListNode *tmphead = head;
        ListNode *leftNode = head;
        while (i<left) {
            tmphead = tmphead->next;
            i++;
        }
        leftNode = tmphead;
        int k = 0;
        while (i <= right ) {
            cache[k++] = tmphead->val;
            tmphead = tmphead->next;
            i++;
        }

        for(int i = (right - left); i >= 0; i--) {
            leftNode->val = cache[i];
            leftNode = leftNode->next;
        }
        return head;
    }
};/**
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
      ListNode* reverseBetween(ListNode* head, int left, int right) {
          if(left == right) {
              return head;
          }

          int i = 1;
          int cache[right - left + 1];
          ListNode *tmphead = head;
          ListNode *leftNode = head;
          while (i<left) {
              tmphead = tmphead->next;
              i++;
          }
          leftNode = tmphead;
          int k = 0;
          while (i <= right ) {
              cache[k++] = tmphead->val;
              tmphead = tmphead->next;
              i++;
          }

          for(int i = (right - left); i >= 0; i--) {
              leftNode->val = cache[i];
              leftNode = leftNode->next;
          }
          return head;
      }
  };
