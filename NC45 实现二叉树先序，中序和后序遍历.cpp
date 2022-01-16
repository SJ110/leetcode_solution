/**
 * struct TreeNode {
 *    int val;
 *    struct TreeNode *left;
 *    struct TreeNode *right;
 * };
 */

class Solution {
public:
    /**
     *
     * @param root TreeNode类 the root of binary tree
     * @return int整型vector<vector<>>
     */
    vector<vector<int> > threeOrders(TreeNode* root) {
        // write code here
        vector<vector<int>> retVec;
        vector<int> helperVec;
        
        preOrderTree(helperVec, root);
        retVec.push_back(helperVec);
        helperVec.clear();
        
        Inorder(helperVec, root);
        retVec.push_back(helperVec);
        helperVec.clear();
        
        Backorder(helperVec, root);
        
        retVec.push_back(helperVec);
        return retVec;
    }
    void preOrderTree(vector<int>&container,TreeNode* root) {
        if(!root) return;
        stack<TreeNode *>helper;
        while(root || !helper.empty()) {
              while(root) {
                  helper.push(root);
                  container.push_back(root->val);
                  root = root->left;
              }
            TreeNode *tmp = helper.top();
            helper.pop();
            root = tmp->right;
        }
        return;
    }
    void Inorder(vector<int>&container,TreeNode* root) {
        if(!root) return;
        stack<TreeNode *>helper;
        while(root || !helper.empty()) {
              while(root) {
                  helper.push(root);
                  root = root->left;
              }
            TreeNode *tmp = helper.top();
            container.push_back(tmp->val);
            helper.pop();
            root = tmp->right;
        }
        return;
    }
    void Backorder(vector<int>&container,TreeNode* root) {
        if(!root) return;
        stack<TreeNode *>helper1,helper2;
        helper1.push(root);
        while(!helper1.empty()) {
            TreeNode *tmp = helper1.top();
            helper2.push(tmp);
            helper1.pop();
            if(tmp->left) {
                helper1.push(tmp->left);
            }
            if(tmp->right) {
                helper1.push(tmp->right);
            }
        }
        while(!helper2.empty()) {
            container.push_back(helper2.top()->val);
            helper2.pop();
        }
    }
};
