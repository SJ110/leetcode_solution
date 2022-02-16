/*
struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
    TreeNode(int x) :
            val(x), left(NULL), right(NULL) {
    }
};*/
class Solution {
public:
    vector<vector<int>> FindPath(TreeNode* root,int expectNumber) {
        vector<vector<int>> ret;
        stack<TreeNode *>helper;
        int cnt = 0;
        vector<int> tmp;
        while(root || !helper.empty()) {
            while(root) {
                helper.push(root);
                cnt = cnt + root->val;
                tmp.push_back(root->val);
                if(root->left) {
                    root = root->left;
                } else {
                    root = root->right;
                }
            }
            TreeNode *node = helper.top();
            if(expectNumber == cnt && !node->left && !node->right) {
                ret.push_back(tmp);
            }
            helper.pop();
            tmp.pop_back();
            cnt = cnt - node->val;
            if(!helper.empty() && helper.top()->left == node) {
                /// 取出当前栈顶,并且当前栈顶节点还没有没遍历过
                root = helper.top()->right;
            } else {
                ///在下一次循环将栈顶pop
                root = nullptr;
            }
        }
        return ret;
    }
};
