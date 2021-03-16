/*
 很朴素的方式，先横着遍历增加Y，在竖着遍历增加X，在横着遍历减少Y，在竖着遍历减少X，
 */


class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector <vector<int>> array(n,vector<int>(n));
        int lowerX = 0,lowerY = 0, upperX = n-1,upperY = n-1;
        int arrayIndicator = 1;
        while(lowerX <= upperX || lowerY <= upperY) {
            /// lowerX++
            for (int i = lowerY;i <= upperY; i++){
                array[lowerX][i] = arrayIndicator++;
            }
            lowerX++;
            /// upperY --
            for (int i = lowerX; i <= upperX; i++){
                array[i][upperY] = arrayIndicator++;
            }
            upperY--;
            /// upperX --
            for (int i = upperY;i>=lowerY; i--) {
                array[upperX][i] = arrayIndicator++;
            }
            upperX--;
            /// lowerY++
            for (int i = upperX; i>= lowerX;i--){
                array[i][lowerY]= arrayIndicator++;
            }
            lowerY++;
        }
        return array;
    }
};
