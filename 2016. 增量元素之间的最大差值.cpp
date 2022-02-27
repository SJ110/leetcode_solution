class Solution {
public:
    int maximumDifference(vector<int>& nums) {
        /// 与买卖股票类似
        int ret = -1;
        int minum = nums[0];
        for (int i = 1;i<nums.size();i++) {
            int tmp = nums[i] - minum;
            if (tmp > ret) {
                ret = tmp;
            } else {
                if (minum > nums[i]) {
                    minum = nums[i];
                }
            }
        }
        if (ret == 0) return -1;
        return ret;
    }
};
