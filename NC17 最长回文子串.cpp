class Solution {
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     *
     * @param A string字符串
     * @return int整型
     */
    int getLongestPalindrome(string A) {
        // write code here
        int maxLen = 1;
        int head = 0,tail = 0, size = A.length();
        int tmpCount = 1;
        for (int i = 0; i < size;i++) {
            head = i-1,tail = i+1;
            tmpCount = 1;
            while(head>=0 && tail < size) {
                if(A[head] == A[tail]) {
                    head--;
                    tail++;
                    tmpCount = tmpCount + 2;
                } else {
                    break;
                }
            }
            if(tmpCount>maxLen) maxLen = tmpCount;
            tmpCount = 0;
            head = i-1;tail = i;
            while(head>=0 && tail < size) {
                if(A[head] == A[tail]) {
                    head--;
                    tail++;
                    tmpCount = tmpCount + 2;
                } else {
                    break;
                }
            }
            if(tmpCount>maxLen) maxLen = tmpCount;
        }
        return maxLen;
    }
};
