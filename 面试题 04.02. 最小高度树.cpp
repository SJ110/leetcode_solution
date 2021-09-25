/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
/*
 递归解决，没啥好说的
 */
class Solution {
public:
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        if(nums.size() == 0) return NULL;
         int left = 0,right = nums.size()-1;
        // int mid = left+(right-left)/2;
        // TreeNode *root = TreeNode(nums[mid]);
        // root->left = sortedArrayToBSTHelper(nums,left,mid-1);
        // root->right = sortedArrayToBSTHelper(nums,mid+1,right);
        // return root;
        return sortedArrayToBSTHelper(nums,left,right);
    }

private:
    TreeNode* sortedArrayToBSTHelper(vector<int>& nums,int left, int right) {
        if(left == right) {
            TreeNode *leaf =  new TreeNode(nums[left]);
            return leaf;
        }
        TreeNode *root = NULL;
        if(left<right) {
            int mid = left + (right-left)/2;
            root = new TreeNode(nums[mid]);
            root->left = sortedArrayToBSTHelper(nums,left,mid-1);
            root->right = sortedArrayToBSTHelper(nums,mid+1,right);
        }
        return root;
    }
};
