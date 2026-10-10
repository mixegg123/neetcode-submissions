class Solution {
public:
    int climbStairs(int n) {
        //dp[0] = 1
        //dp[1] = 1
        //dp[2] = dp[i-1] + dp[i-2];
        //d[[3] = dp[1] + dp[2]
        vector<int> dp(n+1, 0);
        dp[0] = dp[1] = 1;
        for(int i =2;i<=n;i++)
            dp[i] = dp[i-1] + dp[i-2];
        return dp[n];
    }
};
