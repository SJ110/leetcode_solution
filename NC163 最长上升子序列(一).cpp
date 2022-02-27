class Solution {
public:
    /**
     * retrun the longest increasing subsequence
     * @param arr int整型vector the array
     * @return int整型vector
     */
    int LIS(vector<int>& arr) {
        // write code here
        vector<int> dp(arr.size(),1);
        int maxLen = 0;
        for(int i = 0;i<arr.size();i++) {
            for(int j = 0;j < i;j++) {
                  if(arr[i]>arr[j]) {
                      if (dp[i]< dp[j]+1) {
                          dp[i] = dp[j]+1;
                      }
                  }
            }
            if (dp[i]>maxLen) {
                maxLen =dp[i];
            }
        }
        return maxLen;
    }
    
};
