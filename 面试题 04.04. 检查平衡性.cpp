/**
 自底向上的思路还是没有太搞明白
 */
class Solution {
public:
    bool isBalanced(TreeNode* root) {
        if(!root) return true;
        // if(abs(getTreeHeight(root->left)-getTreeHeight(root->right)) > 1) {
        //     return false;
        // }
        // return isBalanced(root->left) && isBalanced(root->right);
        int height = 0;
        return isBalancedHelper(root,height);
        
    }

private:
    int getTreeHeight(TreeNode *root) {
        if(!root) return 0;
        int leftHeight = getTreeHeight(root->left)+1;
        int rightHeight = getTreeHeight(root->right)+1;
        return max(leftHeight,rightHeight);
    }

    bool isBalancedHelper(TreeNode *root, int &height) {
        if(!root) {
            height = 0;
            return true;
        }
        int leftHeight = 0,rightHeight = 0;
        if(isBalancedHelper(root->left,leftHeight) &&
            isBalancedHelper(root->right,rightHeight)) {
                if(abs(leftHeight -rightHeight) <= 1) {
                    height = max(leftHeight,rightHeight)+1;
                    return true;
                }
        }
        return false;
    }
};
