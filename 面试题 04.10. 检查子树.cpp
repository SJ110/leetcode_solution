/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
//先序遍历
class Solution {
public:
    bool checkSubTree(TreeNode* t1, TreeNode* t2) {
        if(!t1 && !t2) return true;
        if(!t1) return false;
        bool checked = checkSubTreeHelper(t1,t2);
        if(checked) {
            return true;
        }
        return (checkSubTree(t1->left,t2) || checkSubTree(t1->right,t2));
    }

private:
    bool checkSubTreeHelper (TreeNode *t1, TreeNode *t2) {
        if(!t1 && !t2) return true;
        if((t1 && !t2) || (!t1 && t2)) return false;
        if(t1->val == t2->val) {
            return (checkSubTreeHelper(t1->left,t2->left) && checkSubTreeHelper(t1->right,t2->right));
        }
        return false;
    }
};
