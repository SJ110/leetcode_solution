/*
struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
    TreeNode(int x) :
            val(x), left(NULL), right(NULL) {
    }
};
*/
class Solution {
public:
    vector<vector<int> > Print(TreeNode* pRoot) {
        vector<vector<int>> ret;
        if(!pRoot) return ret;
        stack<TreeNode *>hStack;
        stack<TreeNode *>hStack2;
        hStack2.push(pRoot);
        while(!hStack.empty() || !hStack2.empty()) {
            vector<int> tmp;
            while(!hStack2.empty()) {
                TreeNode *node = hStack2.top();
                tmp.push_back(node->val);
                hStack2.pop();
                if(node->left) {
                    hStack.push(node->left);
                }
                if(node->right) {
                    hStack.push(node->right);
                }
            }
            if(!tmp.empty()) ret.push_back(tmp);
            tmp.clear();
            while(!hStack.empty()) {
                TreeNode *node = hStack.top();
                tmp.push_back(node->val);
                hStack.pop();
                if(node->right) {
                    hStack2.push(node->right);
                }
                if(node->left) {
                    hStack2.push(node->left);
                }
            }
            if(!tmp.empty()) ret.push_back(tmp);
        }
        return ret;
    }
};
