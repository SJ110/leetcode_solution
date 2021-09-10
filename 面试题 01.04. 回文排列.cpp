/**
 map存储数据，然后遍历map即可
 */
class Solution {
public:
    bool canPermutePalindrome(string s) {
        map<char, int> sHelper;
        for(auto iter : s) {
            sHelper[iter]++;
        }
        int oddCount = 0;
        for (auto iter : sHelper) {
            if (iter.second % 2) oddCount++;
        }
        return oddCount <= 1;
    }
};
