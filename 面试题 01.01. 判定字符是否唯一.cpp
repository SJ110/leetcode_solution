/*
 这道题评论的高赞回答更有意义
 */
class Solution {
public:
    bool isUnique(string astr) {
        if(astr.length()==0) return true;
        for (int i = 0; i<astr.length()-1;i++){
            for (int j = i+1; j< astr.length(); j++) {
                if(astr[i] == astr[j])
                    return false;
            }
        }
        return true;
    }
};
