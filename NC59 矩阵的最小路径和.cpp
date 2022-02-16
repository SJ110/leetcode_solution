class Solution {
public:
    /**
     *
     * @param matrix int整型vector<vector<>> the matrix
     * @return int整型
     */
    int minPathSum(vector<vector<int> >& matrix) {
        // write code here
        vector<vector<int>> dp = matrix;
        
        for(int i = 1;i<matrix.size();i++) {
            dp[i][0] = dp[i-1][0]+dp[i][0];
        }
        for(int j = 1;j<matrix[0].size();j++) {
            dp[0][j] = dp[0][j-1]+dp[0][j];
        }
        for(int i = 1;i<matrix.size();i++) {
            for(int j = 1;j<matrix[0].size();j++) {
                dp[i][j] = min(dp[i-1][j],dp[i][j-1])+matrix[i][j];
            }
        }
        return dp[matrix.size()-1][matrix[0].size()-1];
    }
};
