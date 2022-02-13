class Solution {
public:
    vector<int> spiralOrder(vector<vector<int> > &matrix) {
        int row = matrix.size();
        int col = 0;
        if(row>0)  {
            col = matrix[0].size();
        }
        vector<int> retVec;
        int rowMin = 0,rowMax = row - 1;
        int colMin = 0,colMax = col - 1;
        while((rowMin <= rowMax) || (colMin <= colMax)) {
            for(int i = colMin;i<=colMax;i++) {
                if(rowMin <= rowMax)
                   retVec.push_back(matrix[rowMin][i]);
            }
            rowMin++;
            for(int j = rowMin;j<=rowMax;j++) {
                if(colMin <= colMax)
                   retVec.push_back(matrix[j][colMax]);
            }
            colMax--;
            for(int i = colMax;i>=colMin;i--) {
                if(rowMin<=rowMax)
                   retVec.push_back(matrix[rowMax][i]);
            }
            rowMax--;
            for(int j = rowMax;j>=rowMin;j--) {
                if(colMin<=colMax)
                   retVec.push_back(matrix[j][colMin]);
            }
            colMin++;
        }
        return retVec;
    }
};
