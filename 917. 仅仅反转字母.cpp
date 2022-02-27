class Solution {
public:
    string reverseOnlyLetters(string s) {
        int head = 0, tail = s.size()-1;
        while(head<tail) {
            while (head<tail &&((s[head]<'a' || s[head]>'z') && (s[head]<'A' || s[head]>'Z'))) {
                head++;
            }
            while (head<tail && ((s[tail]<'a'||s[tail]>'z')&&(s[tail] < 'A' || s[tail] > 'Z'))) {
                tail--;
            }
            swap(s[head],s[tail]);
            head++;
            tail--;
        }
        return s;
    }
};
