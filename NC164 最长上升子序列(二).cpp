class Solution {
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     * 该数组最长严格上升子序列的长度
     * @param a int整型vector 给定的数组
     * @return int整型
     */
    int LIS(vector<int>& arr) {
        // write code here
        /// 数组长度过大,使用贪心
        vector<int> slow;
        int maxLen = 0;
        for(int i = 0; i < arr.size();i++) {
            int element = arr[i];
            if(slow.empty() || slow.back() <= element) {
                slow.push_back(element);
            } else {
                int idx = binarySearchIdx(slow, element);
                slow[idx] = element;
            }
        }
        for(int i = 0;i<slow.size();i++) {
            cout << slow[i]<< " ";
        }
        return slow.size();
    }
    /// 找到target插入数组中的最小索引
    int binarySearchIdx(vector<int> &arr,int target) {
        int left = 0;
        int right = arr.size()-1;
        int mid = 0;
        while(left<=right) {
            mid = (left+right)/2;
            if(arr[mid] < target) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }
        return left;
    }
};
