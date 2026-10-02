class Solution {
public:
    int change(int amount, vector<int>& coins) {
#if 0//recursive
        int count = 0;
        dfs(coins, 0, amount, count);
        return count;
#else //2D dp[i][j], up to i index and include, j is target to amount

        /*
建立一個 2D 陣列 dp[i][j]：

i：只考慮前 i 種硬幣（coins[0 ... i-1]）

j：當前要湊的金額

dp[i][j] 代表：只用前 i 種硬幣，湊出金額 j 的組合總數。
        */
#if 0//2d
        int n = coins.size();
        vector<vector<int>> dp(n+1, vector<int>(amount+1, 0));
        //dp[i][0] = 1
        //dp[0][j] = 0;
        for(int i = 1; i<=n; i++)
            dp[i][0] = 1;
        for(int i = 1;i<=n;i++)
        {
            for(int j = 1; j<=amount;j++)
            {
                //printf("i:%d, coins[i-1]:%d, j=%d\n", i, coins[i-1], j);
                if(j>=coins[i-1])
                    dp[i][j] = dp[i-1][j] + dp[i][j-coins[i-1]];
                else
                    dp[i][j] = dp[i-1][j];
                    
               // printf("dp[%d][%d]:%d\n", i, j, dp[i][j]);
               // printf("dp[%d][%d]:%d\n", i-1, j, dp[i-1][j]);
            }
        }
        
        return dp[n][amount];
#else
        vector<int> dp(amount +1, 0);
        dp[0] = 1;
        for(int const coin : coins)
        {
            for(int j = coin; j<=amount; j++)
                dp[j] = dp[j] + dp[j-coin];
        }
        return dp[amount];
#endif
#endif
    }

    void dfs(vector<int> &coins, int start, int target, int &count)
    {
        if(target == 0)
        {
            count++;
            return;
        }
        if(target < 0)
            return;
        
        for(int i = start; i<coins.size(); i++)
        {
            dfs(coins,i, target - coins[i], count);
        }
    }
};
