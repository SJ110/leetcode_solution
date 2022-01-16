class Solution {
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     * 将给定数组排序
     * @param arr int整型vector 待排序的数组
     * @return int整型vector
     */
    vector<int> MySort(vector<int>& arr) {
        // write code here
        sort(arr.begin(), arr.end());
        return arr;
        
        
        // write code here
//        for (int i = 1; i < arr.size();i++) {
//           for (int j = i;j>0 && arr[j]<arr[j-1];j--) {
//               swap(arr[j], arr[j-1]);
//            }
//         }
//         cutArray(arr, 0, arr.size()-1);
//         return arr;
    }
    void cutArray(vector<int>& nums,int head,int tail) {
        if(head >= tail) return;
        int flag = head,newHead = head,newTail = tail;
        
        while (head < tail) {
            while(head < tail && nums[head] < nums[flag]) {
                head++;
            }
            while(head < tail && nums[tail] >= nums[flag]) {
                tail--;
            }
            if(head >= tail) break;
            swap(nums[head], nums[tail]);
        }
        swap(nums[flag],nums[head]);
        cutArray(nums,newHead,head-1);
        cutArray(nums,head+1, newTail);
    }

    
};
