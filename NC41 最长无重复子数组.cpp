class Solution {
public:
    /**
     *
     * @param arr int整型vector the array
     * @return int整型
     */
    int maxLength(vector<int>& arr) {
        // write code here
        set<int>helper;
        int head = 0,tail = 0;
        int len = 0;
        for(int i = 0;i<arr.size();i++) {
            tail = i;
            if(helper.find(arr[i])==helper.end()) {
                helper.insert(arr[i]);
            } else {
                if(len < helper.size()) {
                    len = helper.size();
                }
                ///移除第一个相同元素之前的
                int j = head;
                while(arr[j]!= arr[i]) {
                    j++;
                }
                /// 移除第一个相同元素
                j++;
                head = j;
                ///重建set
                helper.clear();
                while(j<=tail) {
                    helper.insert(arr[j++]);
                }
                
            }
        }
        if(len<helper.size()) len = helper.size();
        return len;
    }
};
