class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        int cache[9];
        memset(cache,0,sizeof(cache));
        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                if(board[i][j] == '.') {
                    continue;
                }
                cache[(board[i][j] - '1')]++;
                if(cache[(board[i][j] - '1')] > 1) {
                    return false;
                }
            }
            memset(cache,0,sizeof(cache));
        }

        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                if(board[j][i] == '.') {
                    continue;
                }
                cache[(board[j][i] - '1')]++;
                if(cache[(board[j][i] - '1')] > 1) {
                    return false;
                }
            }
            memset(cache,0,sizeof(cache));
        }

        for (int i = 0; i < 9; i= i + 3) {
            for (int j = 0; j < 9; j = j + 3) {
                for (int k = i; k < i+3; k++) {
                    for (int l = j; l < j+3; l++) {
                        if(board[k][l] == '.') {
                            continue;
                        }
                        cache[(board[k][l] - '1')]++;
                        if(cache[(board[k][l] - '1')] > 1) {
                            return false;
                        }
                    }
                }
                memset(cache,0,sizeof(cache));
            }
        }
        return true;
    }
};
