/*
 使用string拼接会超时，很久没用c++了，忘记原理。
 使用stringstream可以oc
 */
class Solution {
public:
    string replaceSpaces(string S, int length) {
        stringstream ss;
        for (int i = 0; i<length; i++) {
            if(S[i] != ' ') {
                ss<< S[i];
            } else {
                ss<<"%20";
            }
        }
        return ss.str();
    }
};
