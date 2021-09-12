/**
 上下左右四个位置上相互交换
 */
class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = n;
        int tmp0, tmp1,tmp2;
        for (int i=0;i<m;i++) {
            for ( int j = i; j<m-1; j++) {
                tmp0 = matrix[j][n-i-1];
                matrix[j][n-i-1] = matrix[i][j];
                tmp1 = matrix[n-i-1][n-j-1];
                matrix[n-i-1][n-j-1] = tmp0;
                tmp2 = matrix[n-j-1][i];
                matrix[n-j-1][i] = tmp1;
                matrix[i][j] = tmp2;
            }
            m--;
        }
    }
};
