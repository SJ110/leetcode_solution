class Solution {
public:
    /**
     *
     * @param numbers int整型vector
     * @param target int整型
     * @return int整型vector
     */
    vector<int> twoSum(vector<int>& numbers, int target) {
        // write code here
        vector<int>ret;
        map<int,int>helper;
        for(int i = 0;i<numbers.size();i++) {
            if(helper[target-numbers[i]]) {
                ret.push_back(helper[target-numbers[i]]);
                ret.push_back(i+1);
                break;
            }
             helper[numbers[i]] = i+1;
        }
        return ret;
    }
};
