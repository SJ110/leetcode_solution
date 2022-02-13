class Solution {
public:
    /**
     * 反转字符串
     * @param str string字符串
     * @return string字符串
     */
    string solve(string str) {
        // write code here
        string ret = "";
        for(int i = 0;i<str.length();i++) {
            ret = str[i]+ret;
        }
        return ret;
    }
};
