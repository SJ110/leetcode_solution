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
 感觉有点为了做而做了，下次遇到类似的，要尝试下非递归的方式了
 */
class Solution {
    vector<TreeNode *> helper;
public:
    TreeNode* inorderSuccessor(TreeNode* root, TreeNode* p) {
        inorderSuccessorHelper(root);
        for(int i=0;i<helper.size();i++) {
            if(helper[i] == p) {
                if((i+1) < helper.size()) {
                    return helper[i+1];
                } else {
                    return NULL;
                }
            }
        }
        return NULL;
    }
private:
    void inorderSuccessorHelper(TreeNode *root) {
         if(!root) return;
         inorderSuccessorHelper(root->left);
         helper.push_back(root);
         inorderSuccessorHelper(root->right);
    }
};
