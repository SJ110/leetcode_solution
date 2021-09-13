class Solution {
public:
    bool isFlipedString(string s1, string s2) {
        if(s1.length() != s2.length()) return false;

        string ss= s2+s2;
        /// string.find()是o(n2)
        if(ss.find(s1) != -1) return true;
        return false;

    }
};
