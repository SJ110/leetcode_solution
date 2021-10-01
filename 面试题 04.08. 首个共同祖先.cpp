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
 下次做不能使用额外数据结构了
 */
class Solution {
    bool markp;
    bool markq;
    vector<TreeNode *>helper;
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        backOrderTree(root);
        for(auto iter : helper) {
            markq = markp = false;
            if(preOderTree(iter,p,q)) {
                return iter;
            }
        }
        return NULL;
    }

private:
    void backOrderTree(TreeNode *root) {
        if(!root) return;
        backOrderTree(root->left);
        backOrderTree(root->right);
        helper.push_back(root);
    }

    bool preOderTree(TreeNode *root,TreeNode *p,TreeNode *q) {
        if(!root) return false;
        if(root == p) markp = true;
        if(root == q) markq = true;
        preOderTree(root->left,p,q);
        preOderTree(root->right,p,q);
        if(markp && markq) {
            return true;
        }
        return false;
    }
};
