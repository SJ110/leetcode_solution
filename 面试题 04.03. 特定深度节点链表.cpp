/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
/*
 非递归方式想了一下，比较简单，就没有实现了，下次来
 层序遍历的递归方式是通过先序遍历实现的
 */
class Solution {
    vector<ListNode*> ret;
public:
    vector<ListNode*> listOfDepth(TreeNode* tree) {
        listOfDepthHelper(tree,0);
        return ret;
    }

private:
    void listOfDepthHelper(TreeNode *tree,int depth) {
        if(!tree) return;
        ListNode *node = new ListNode(tree->val);
        if(depth>=ret.size()) {
            ret.push_back(node);
        } else {
            ListNode *cur = ret[depth];
            while(cur->next) {
                cur = cur->next;
            }
            cur->next = node;
        }
        listOfDepthHelper(tree->left,depth+1);
        listOfDepthHelper(tree->right,depth+1);
    }
};
