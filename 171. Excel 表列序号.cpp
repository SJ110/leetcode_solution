class Solution {
public:
    int titleToNumber(string columnTitle) {
        int ret = 0,j = 0;
        for (int i = columnTitle.size()-1;i>=0;i--) {
            int tmp = columnTitle[i]-'A'+1;
            ret = ret + pow(26,j++)*tmp;
        }
        return ret;
    }
};
