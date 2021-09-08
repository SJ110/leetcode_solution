/*
 为了在保存[1,2]后能够继续往下循环，
 在执行递归后，pop出一个，保证下次循环的时候可以取到[1,3]
 */
class Solution {
    vector<vector<int>> ret;
public:
    vector<vector<int>> combine(int n, int k) {
        for (int i=1;i<=n;i++){
            vector<int> inputs;
            inputs.push_back(i);
            sInset(inputs,i+1,n,k);
        }
        return ret;
    }
    void sInset(vector<int>&inputs, int i,int n, int k) {
        if(inputs.size()<k) {
            for(;i<=n;i++){
                inputs.push_back(i);
                sInset(inputs,i+1,n,k);
                /// 这一步是最关键的
                inputs.pop_back();
            }
        } else {
            ret.push_back(inputs);
        }
    }
};
