class Solution {
public:
    string countAndSay(int n) {
        if(n == 1) {
            return "1";
        }
        string cache = "1";
        for(int i =2; i<= n; i++) {
            int len = cache.length();
            string tmp = "";
            for (int j = 0; j < len; j++) {
                int cnt = 1;
                 for (int k = j+1; k<len; k++) {
                     if(cache[k] == cache[j]) {
                         cnt ++;
                         j = k;
                     }else {
                         break;
                     }
                 }
                 tmp = tmp + to_string(cnt)+cache[j];
            }
            cache = tmp;
        }
        return cache;
    }
};
