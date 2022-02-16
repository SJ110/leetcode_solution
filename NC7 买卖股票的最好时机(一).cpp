class Solution {
public:
    /**
     *
     * @param prices int整型vector
     * @return int整型
     */
    int maxProfit(vector<int>& prices) {
        // write code here
        if(prices.size()<=1) return 0;
        int buy = prices[0];
        int maxPrf = 0;
        for(int i = 1;i < prices.size();i++) {
            if (prices[i] > buy) {
                if (maxPrf < (prices[i]-buy)) {
                    maxPrf = prices[i] - buy;
                }
            } else {
                buy = prices[i];
            }
        }
        return maxPrf;
    }
};
