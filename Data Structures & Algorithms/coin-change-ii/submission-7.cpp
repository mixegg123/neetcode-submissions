class Solution {
public:
    int change(int amount, vector<int>& coins) {
        //dp[coins][target]
        int n = coins.size();

        vector<vector<int>> dp(n+1, vector<int>(amount+1, 0));
        //dp[i][0] = 1;
        for(int i = 1;i<=n;i++)
            dp[i][0] = 1;

        for(int j = 1; j<=amount;j++)
        {
            for(int i = 1;i<=n;i++)
            {
                int w = coins[i-1];
                dp[i][j] = dp[i-1][j];
                if(w <= j)
                    //take, or not take
                    dp[i][j] += dp[i][j-w];
            }
        }
        return dp[n][amount];
    }
};
