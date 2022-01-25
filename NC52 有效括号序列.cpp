class Solution {
public:
    /**
     *
     * @param s string字符串
     * @return bool布尔型
     */
    bool isValid(string s) {
        // write code here
        stack<char> helper;
        for(int i = 0;i<s.size();i++) {
            if(!helper.empty()) {
                char str = helper.top();
                if((str == '[' && s[i] == ']') || (str == ']' && s[i] == '[') ||
                   (str == '(' && s[i] == ')') || (str == ')' && s[i] == '(') ||
                   (str == '{' && s[i] == '}') || (str =='}') && s[i] == '{')
                    helper.pop();
                else {
                    helper.push(s[i]);
                }
            } else {
              helper.push(s[i]);
            }
        }
        return helper.empty();
    }
};
