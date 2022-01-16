class Solution {
public:
    vector<int> GetLeastNumbers_Solution(vector<int> input, int k) {
        vector<int> retVec;
        if(input.size() == 0 || k == 0) {
            return retVec;
        }
        quickSort(input);
//         for(int i =0 ;i<input.size();i++) {
//             cout<<input[i] << " ";
//         }
        for(int i = 0; i<k && i<input.size();i++) {
            retVec.push_back(input[i]);
        }
        return retVec;
    }
    /// quick sort
    void quickSort(vector<int>&nums) {
        int head = 0,tail = nums.size()-1;
        int flag = head;
        cutArray (nums,flag,head,tail);
    }
    
    void cutArray(vector<int>&nums,int flag,int head,int tail) {
        if(head >= tail) return;
        int newHead = head,newTail = tail;
        while(head<tail) {
            while(head<tail && nums[head] < nums[flag]) {
                head++;
            }
            while(tail>head && nums[tail] >= nums[flag]) {
                /// 这一步必须这样做,把大于等于哨兵的值都放到哨兵右边
                tail--;
            }
            if(tail<=head) {
                break;
            }
            swap(nums[head], nums[tail]);
        }
        swap(nums[flag], nums[head]);
        cutArray(nums, newHead, newHead, head-1);
        cutArray(nums, head+1, head+1, newTail);
    }
};
