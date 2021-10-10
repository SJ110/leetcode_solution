/**
 除二取余法
 */
class Solution {
public:
    int insertBits(int N, int M, int i, int j) {
        int *Nhelper = toBinary(N);
        int *Mhelper = toBinary(M);
        // for(int i=0;i<=31;i++) {
        //     printf("%d",Nhelper[i]);
        // }
        // printf("\n");
        // for(int i=0;i<=31;i++) {
        //     printf("%d",Mhelper[i]);
        // }
        for(int idx = 31-i,midx = 31;idx>=31-j;idx--) {
            Nhelper[idx] = Mhelper[midx];
            midx--;
        }
        // printf("\n");
        // for(int i=0;i<=31;i++) {
        //     printf("%d",Nhelper[i]);
        // }
        return toTens(Nhelper);
    }

    int* toBinary(int idx) {
        int* a = new int[32];
        memset(a,0,sizeof(int)*32);
        bool flag = 0;
        if(idx<0) {
            idx = -(idx+1);
            flag = 1;
        }
        int i = 31;
        while(idx>0) {
            a[i--] = idx%2;
            idx = idx/2;
        }
        if(flag == 1) {
            while(i>=0) {
                a[i--] = 1;
            }
        }
        return &a[0];
    }

    int toTens(int *a) {
        bool flag = 0;
        if(a[0] == 1) {
            flag = 1;
            for(int i = 0;i<=31;i++) {
                a[i] = -a[i];
            }
        }
        long ret = 0;
        for(int i = 0;i<=31;i++) {
            ret = ret+a[i]*pow(2,31-i);
        }
        if(flag) {
            ret++;
            return -ret;
        }
        return ret;
    }
};
