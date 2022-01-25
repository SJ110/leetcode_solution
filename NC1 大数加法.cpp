class Solution {
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     * 计算两个数之和
     * @param s string字符串 表示第一个整数
     * @param t string字符串 表示第二个整数
     * @return string字符串
     */
    string solve(string s, string t) {
        // write code here
        stack<char>helpr;
        int len1 = s.length()-1;
        int len2 = t.length()-1;
        int forward = 0;
        while(len1>=0 && len2>=0) {
            char s1 = s[len1--],t1 = t[len2--];
            int sum = (s1-'0') + (t1-'0')+forward;
            if(sum>=10) {
                forward = 1;
                helpr.push(sum-10+'0');
            } else {
                forward = 0;
                helpr.push(sum+'0');
            }
        }
        while(len1>=0) {
            int sum = s[len1--]-'0'+forward;
            if(sum>=10) {
                forward = 1;
                helpr.push(sum-10+'0');
            } else {
                forward = 0;
                helpr.push(sum+'0');
            }
        }
        while(len2>=0) {
            int sum = t[len2--]-'0'+forward;
            if(sum>=10) {
                forward = 1;
                helpr.push(sum-10+'0');
            } else {
                forward = 0;
                helpr.push(sum+'0');
            }
        }
        
        string ret = forward == 1?"1":"";
        while(!helpr.empty()) {
            ret = ret+helpr.top();
            helpr.pop();
        }
        return ret;
    }
};
