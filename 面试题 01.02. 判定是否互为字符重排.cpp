/**
 两个map存储数据，在遍历map比较
 */
class Solution {
public:
    bool CheckPermutation(string s1, string s2) {
        if(s1.length() != s2.length())
            return false;
        map<char,int> s1Helper;
        map<char,int> s2Helper;
        for (int i = 0; i < s1.length(); i++) {
            s1Helper[s1[i]]++;
            s2Helper[s2[i]]++;
        }
        for(auto iter : s1Helper) {
            if(iter.second != s2Helper[iter.first])
              return false;
        }
        return true;
    }
};
