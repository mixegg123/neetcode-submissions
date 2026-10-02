class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        //absolute dp, and dp[i] is cost
        //dp[i] = min(dp[i-1], dp[i-2])
        int n = cost.size();
        vector<int> dp(n, 0);
        dp[0] = cost[0];
        dp[1] = cost[1];
        for(int i = 2; i<n; i++)
        {
            dp[i] = cost[i] + min(dp[i-1], dp[i-2]);
            printf("dp[%d]: %d\n", i, dp[i]);
        }

        return min(dp[n-1], dp[n-2]);
    }
};
