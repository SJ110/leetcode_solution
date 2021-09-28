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
 可以不需要数组，直接中序遍历比较
 */
class Solution {
    vector<long> helper;
public:
    bool isValidBST(TreeNode* root) {
        midoderTree(root);
        if(helper.size() < 1) return true;
        for(int i=1; i<helper.size();i++) {
            if(helper[i-1]>=helper[i]) {
                return false;
            }
        }
        return true;
    }

private:
    void midoderTree(TreeNode *root) {
        if(!root) return;
        midoderTree(root->left);
        helper.push_back(root->val);
        midoderTree(root->right);
    }
};
