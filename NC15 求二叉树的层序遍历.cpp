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
     * @param root TreeNode类
     * @return int整型vector<vector<>>
     */
    vector<vector<int> > levelOrder(TreeNode* root) {
        // write code here
        vector<vector<int> > retVec;
        queue<TreeNode *>helperQue;
        if (!root) return retVec;
        helperQue.push(root);
        while (!helperQue.empty()) {
            vector<int> layerVec;
            queue<TreeNode *>tmp;
            while (!helperQue.empty()) {
                TreeNode *node = helperQue.front();
                layerVec.push_back(node->val);
                if (node->left) {
                    tmp.push(node->left);
                }
                if (node->right) {
                    tmp.push(node->right);
                }
                helperQue.pop();
            }
            if (!layerVec.empty()) {
                retVec.push_back(layerVec);
            }
            helperQue = tmp;
        }
        return retVec;
    }
};
