class Solution {
public:
    int findKth(vector<int> a, int n, int K) {
        // write code here
        /// 堆排序,使用0
        for(int i = n/2;i>=0;i--) {
            makeHeap(a, i, n);
        }
        int m = n;
        while(m>0 && K>0) {
            swap(a[m-1], a[0]);
            m--;
            K--;
            makeHeap(a, 0, m);
        }
        return a[m];
    }
    ///建大顶堆
    void makeHeap(vector<int>&a,int k,int N) {
        while(2*k+1<N) {
            int j = 2*k+1;
            if(j+1<N && a[j]<a[j+1]) {
                j++;
            }
            if(a[j]>a[k]) {
                swap(a[k], a[j]);
            } else {
                break;
            }
            k = j;
        }
    }
};
