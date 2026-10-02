class Solution {
public:
    int uniquePaths(int m, int n) {
        //backtracing, and not required a visited (go right and down)
        //dx[1, 0]
        //dy[0, 1]
        //dfs -> base condition, reach end, for loop -> summary

#if 0//backtracing
        int res = 0;
        int memo[m][n] = {-1};
        dfs(0, 0, m, n, res);
        return res;
#else //dp
#if 0//2D DP
        vector<vector<int>> dp(m, vector<int>(n, 1));

        for(int i = 1; i<m; i++)
        {
            for(int j = 1;j<n;j++)
                dp[i][j] = dp[i-1][j] + dp[i][j-1];
        }
        return dp[m-1][n-1];
#else //1D DP
        //one dimension, we can leverage previous one
        vector<int> dp(n, 1);
        for(int i = 1; i<m;i++)
            for(int j = 1;j<n;j++)
                dp[j] += dp[j-1];
        return dp[n-1];
#endif

#endif
    }

    void dfs(int i, int j, int m, int n, int &res )
    {
        if(i>=m || j>=n)
            return;

        if(i == m-1 && j == n-1)
        {
            res++;
            return;
        }

        int dx[] = {1, 0};
        int dy[] = {0, 1};

        for(int k = 0; k<2; k++)
        {
            int new_i = i + dx[k];
            int new_j = j + dy[k];
            dfs(new_i, new_j, m, n, res);
        }
        return;
    }

};
