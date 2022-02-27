class Solution {
public:
    string optimalDivision(vector<int>& nums) {
        /// 所有除数>2,因此需要让分子尽可能大
        string retStr = "";
        for (int i = 0;i < nums.size();i++) {
            if (i == (nums.size()-1)) {
                retStr = retStr + to_string(nums[i]);
            } else {
                retStr =  retStr + to_string(nums[i]) + '/';
            }
        }
        if (nums.size() <= 2) {
            return retStr;
        }
        retStr = retStr +')';
        int i = 0;
        while(i<retStr.size() && retStr[i] != '/') {
            i++;
        }
        retStr.insert(i+1,1,'(');
        return retStr;
    }
};
