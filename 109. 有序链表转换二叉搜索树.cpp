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
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    TreeNode* sortedListToBST(ListNode* head) {
        if(!head) {
            return nullptr;
        }
        if(!head->next) {
            TreeNode *root = new TreeNode(head->val);
            return root;
        }
        ListNode *fast = head;
        ListNode *slow = head;
        ListNode *pre = head;
        while(fast) {
            if(fast->next) {
                fast = fast->next->next;
                pre = slow;
                slow = slow->next;
            } else {
                fast = fast->next;
            }
        }
        /// 注意：需要把slow前面的链子剪短，否则无法跳出递归
        TreeNode *root = new TreeNode(slow->val);
        pre->next = nullptr;
        root->left = sortedListToBST(head);
        root->right = sortedListToBST(slow->next);
        return root;
    }
};
