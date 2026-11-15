class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        //dp[i][j] = grid[i][j] + min(dp[i-1][j], dp[i][j-1]);
        //dp[j] = grid[i][j] + min(dp[j] + dp[j-1]);
        int m = grid.size();
        int n = grid[0].size();
        //dp[i][j] = min(dp[i-1][j], dp[i][j-1]) + grid[i][j];
        vector<int> dp(n+1, INT_MAX);
        dp[1] = 0;
        for(int i = 1;i<=m;i++)
        {
            for(int j = 1;j<=n;j++)
            {
                dp[j] = min(dp[j], dp[j-1]) + grid[i-1][j-1];
                printf("i:%d,j:%d, dp: %d, grid: %d\n",i,j,dp[j], grid[i-1][j-1]);
            }
        }
        return dp[n];
    }
};