class Solution {
public:
    string convertToTitle(int columnNumber) {
        string defStr = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
        string ret = "";
        while (columnNumber > 0) {
            columnNumber--;
            int lefted = columnNumber % 26;
            columnNumber = columnNumber / 26;
            ret = defStr[lefted] + ret;
        }
        return ret;
    }
};
