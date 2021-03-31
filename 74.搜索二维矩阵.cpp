/*
 二分查找法
 */

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int row = matrix.size();
        int col = matrix[0].size();
        int isInRow = 0;
        while (isInRow < row) {
            if (matrix[isInRow][col-1] < target) {
                isInRow++;
            }else{
                break;
            }
        }
        if (isInRow < row) {
            int start = 0,end = col-1;
            while (start <= end) {
                int mid = (start + end) / 2;
                if(matrix[isInRow][mid] == target){
                    return true;
                }else if(matrix[isInRow][mid] < target) {
                    start = mid + 1;
                }else if(matrix[isInRow][mid] > target) {
                    end = mid - 1;
                }
            }
            return false;
        }
        return false;
    }
};
