class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int head = 0, tail = nums.size()-1;
        int mid = 0;
        while(head < tail) {
            mid = (head+tail)/2;
            if(nums[mid] != nums[mid-1] && nums[mid] != nums[mid+1]) {
                head = mid;
                break;
            }
            /// 保证每次查找都在奇数个的数组中查找
            if(mid % 2) {
                /// 下标为奇数
                if(nums[mid] == nums[mid-1]) {
                    head = mid + 1;
                } else {
                    tail = mid - 1;
                }
            } else {
                if(nums[mid] == nums[mid+1]) {
                    head = mid+2;
                } else {
                    tail = mid;
                }
            }
        }
        return nums[head];
    }
};
