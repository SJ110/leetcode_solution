class Solution {
public:
    vector<vector<int> > threeSum(vector<int> &num) {
        set<vector<int>> ret;
        vector<vector<int>> ret2;
        map<int,vector<int>> helper;
        if(num.size() < 3) {
            return ret2;
        }
        
        vector<int> nums = num;
        sort(nums.begin(), nums.end());
        for(int i = 0;i<nums.size();i++) {
            for(int j = i+1;j<nums.size();j++) {
                if(helper[-nums[j]].size() != 0) {
                    vector<int> tmp = helper[-nums[j]];
                    tmp.push_back(nums[j]);
                    ret.insert(tmp);
                }
                vector<int> node = {nums[i],nums[j]};
                helper[nums[i]+nums[j]] = node;
                
            }
            helper.clear();
        }
        for(auto it :ret) {
            ret2.push_back(it);
        }
        return ret2;
    }
};
