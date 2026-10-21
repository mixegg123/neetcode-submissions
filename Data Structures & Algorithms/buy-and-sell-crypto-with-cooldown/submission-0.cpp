class Solution {
public:
    int maxProfit(vector<int>& prices) {
        //need three arrays
        //hold[i] time money current at current i
        //sold[i] the time when sold out at current i
        //rest[i] the mony after sell at i-1
        int n = prices.size();
        vector<int> hold(n, 0);
        vector<int> sold(n, 0);
        vector<int> rest(n, 0);

        hold[0] = -prices[0];

        for(int i = 1;i<n;i++)
        {
            hold[i] = max(hold[i-1], rest[i-1] - prices[i]);
            sold[i] = hold[i-1] + prices[i];
            rest[i] = max(rest[i-1], sold[i-1]);
        }

        return max(rest[n-1], sold[n-1]);
    }
};
