/**
 两个集合分别保存为0的行和列。
 分别遍历两个集合
 */
class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        set<int> rowHelper;
        set<int> colHelper;
        int row = matrix.size();
        if (row == 0) return;
        int col = matrix[0].size();
        for (int i = 0; i < row; i++) {
            for(int j = 0;j<col; j++) {
                if(matrix[i][j] == 0) {
                    rowHelper.insert(i);
                    colHelper.insert(j);
                }
            }
        }

        for(auto iter : rowHelper) {
            for (int i=0;i<col;i++) {
                matrix[iter][i] = 0;
            }
        }

        for(auto iter : colHelper) {
            for (int j=0;j<row;j++) {
                matrix[j][iter] = 0;
            }
        }
    }
};
