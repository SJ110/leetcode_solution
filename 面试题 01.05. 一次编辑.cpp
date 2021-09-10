/**
 当长度不同时，对较短的一个做插入元素的动作，即index--
 */
class Solution {
public:
    bool oneEditAway(string first, string second) {
        int firstLen = first.length();
        int secondLen = second.length();
        if (abs(firstLen - secondLen) > 1)
            return false;
        int differ = 0;
        for (int i = 0,j=0 ; i < firstLen && j < secondLen; i++,j++) {
            if(differ > 1) {
                return false;
            }
            if(first[i] != second[j]) {
                differ++;
                if(firstLen == secondLen) {
                } else if(firstLen < secondLen) {
                    i--;
                } else {
                    j--;
                }
            }
        }
        return differ <= 1;
    }
};
