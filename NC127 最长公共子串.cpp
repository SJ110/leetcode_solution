class Solution {
public:
    /**
     * longest common substring
     * @param str1 string字符串 the string
     * @param str2 string字符串 the string
     * @return string字符串
     */
    string LCS(string str1, string str2) {
        // write code here
        int size1 = str1.length(),size2 = str2.length();
        int helper[size1+1][size2+1];
        memset(helper, 0, sizeof(helper));
        int maxLen = 0;
        int maxRow = 0,maxCol = 0;
        for (int i = 1;i<=size1;i++) {
            for (int j = 1;j<=size2;j++) {
                if(str1[i-1] == str2[j-1]) {
                    helper[i][j] = helper[i-1][j-1]+1;
                    if(helper[i][j]>maxLen) {
                        maxLen = helper[i][j];
                        maxRow = i;
                        maxCol = j;
                    }
                } else {
                    helper[i][j] = 0;
                }
            }
        }
        string s = "";
        while(maxLen > 0) {
            s = str2[--maxCol]+s;
            maxLen--;
        }
        return s;
        
    }
};
