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
 这是比较傻瓜的做法，更好的做法应该是保存下每一步的计算结果，这样可以有效减少重复树的遍历计算
 */
class Solution {
    int retCount;
    vector<TreeNode *> helper;
public:
    int pathSum(TreeNode* root, int sum) {
        helper = makeVector(root);
        for(auto iter : helper) {
            preOderTree(iter,0,sum);
        }
        return retCount;
    }
private:
    void preOderTree(TreeNode *root,int checkSum,int sum) {
        if(!root) return;
        if((checkSum + root->val) == sum) retCount++;
        preOderTree(root->left,checkSum+root->val,sum);
        preOderTree(root->right,checkSum+root->val,sum);
        return;
    }

    vector<TreeNode *> makeVector(TreeNode *root) {
        if(!root) return helper;
        helper.push_back(root);
        makeVector(root->left);
        makeVector(root->right);
        return helper;
    }
};
