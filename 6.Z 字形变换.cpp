class Solution {
public:
    string convert(string s, int numRows) {
        if(numRows <= 1) {
            return s;
        }
       int len = s.length();
       char cache[numRows][1000];
       for (int i = 0; i < numRows; i++) {
           memset(cache[i],'0',sizeof(char)*1000);
       }
       int index = 0;
       for (int i = 0; i < 1000; i++) {
           int flag = 0;
           for (int j = 0; j < numRows; j++) {
               if(index >= len) {
                   flag = 1;
                   break;
               }
               cache[j][i] = s[index++];
           }
           for (int k = numRows-2;k >= 1; k--) {
                if(index >= len) {
                   flag = 1;
                   break;
               }
               cache[k][++i] = s[index++];
           }
           if(flag == 1) {
               break;
           }
       }

        string ret = "";
       for (int i = 0; i < numRows; i++) {
           for (int j = 0;j < 1000;j++) {
               if(cache[i][j] != '0') {
                   ret = ret + cache[i][j];
               }
           }
       }
       return ret;
    }
};
