/**
 二进制补码使用 2^31+num表示
 */
class Solution {
public:
    int reverseBits(int num) {
        int* numHelper = toBinary(num);
        int cnt = 0;
        for(int i=0;i<=31;i++) {
            if(numHelper[i] == 0) {
                int tmpCnt = 1;
                int j = i-1;
                while(j>=0 && numHelper[j]==1) {
                    j--;
                    tmpCnt++;
                }
                int k = i+1;
                while(k<=31 && numHelper[k]==1) {
                    k++;
                    tmpCnt++;
                }
                if(tmpCnt > cnt) cnt = tmpCnt;
            }
        }
        if(cnt == 0) return 32;
        return cnt;
    }

    int *toBinary(int num) {
        int *a =new int[32];
        memset(a,0,sizeof(int)*32);
        int flag = 0;
        if(num<0) {
            flag = 1;
            num = pow(2,31)+num;
        }
        int i = 31;
        while(num>0) {
            a[i--] = num%2;
            num = num/2;
        }
        if(flag == 1) a[0] = 1;
        return a;
    }
};
