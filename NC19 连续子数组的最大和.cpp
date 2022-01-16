class Solution {
public:
    int FindGreatestSumOfSubArray(vector<int> array) {
        int ret = -101;
        int sum = 0;
        for(int i = 0;i<array.size();i++) {
            sum = sum + array[i];
            if(sum > ret) {
                ret = sum;
            }
            if(sum<0) {
                sum = 0;
            }
        }
        return ret;
    }
};
