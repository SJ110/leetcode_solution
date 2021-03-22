/*
 没有使用除2取余法。定义一个数组表示1-2^31，用n遍历整个数组计算1的个数。
 负数的2进制表示法，按位取反+1，（2^32+n）
 */


class Solution {
public:
    int hammingWeight(uint32_t n) {
        unsigned int templateArray[32] = {0};
        for (int i = 0;i<32;i++){
            templateArray[i] = pow(2,31-i);
        }
        int ret = 0;
        if (n < 0) n = pow(2,32) + n;
        for (int i = 0;i<32; i++){
            if(n >=templateArray[i]) {
                n= n-templateArray[i];
                ret++;
            }
        }
        return ret;
    }
};
