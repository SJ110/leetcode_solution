/**
 类似于之前的url化，使用stringstream保存输入流
 */
class Solution {
public:
    string compressString(string S) {
        if(S.empty()) return S;
        int slow = 0, fast = 0;
        int len = 0;
        stringstream ss;
        for ( fast = 0; fast < S.length(); fast++) {
            if(S[slow] != S[fast]) {
                ss << S[slow];
                ss << to_string(fast - slow);
                // retString = retString + S[slow] + to_string(fast - slow);
                len = len + 2;
                slow = fast;
            }
        }
        if (S[slow] == S[fast - 1]) {
            ss << S[slow];
            ss << to_string(fast - slow);
            len = len + 2;
        }
        if (len < S.length()) return ss.str();
        return S;
    }
};
