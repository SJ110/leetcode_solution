/**
 markDirty 遇到相等的就markDirty一下，表示计数两次，
 否则表示计数一次。
 在两个数不想等时记一次数。
 循环结束后在做一个兜底处理
 */
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if(nums.size() <= 2) return nums.size();
        bool markDirty = false;
        int slow = 0, fast = 1;
        int retIndex = 0;
        while(fast < nums.size()) {
            if(nums[slow] == nums[fast]) {
                markDirty = true;
                slow++;
                fast++;
            } else {
                if(markDirty == true) {
                    nums[retIndex] = nums[slow];
                    nums[retIndex+1] = nums[slow];
                    retIndex = retIndex + 2;
                    markDirty = false;
                } else {
                    nums[retIndex] = nums[slow];
                    retIndex++;
                }
                slow = fast;
                fast = fast+1;
            }
        }
        if(markDirty == true) {
            nums[retIndex] = nums[slow];
            nums[retIndex+1] = nums[slow];
            retIndex = retIndex+2;
        } else {
            nums[retIndex] = nums[slow];
            retIndex++;
        }
        return retIndex;
    }
};
