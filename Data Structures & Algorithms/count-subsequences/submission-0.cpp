class Solution {
public:
    int numDistinct(string s, string t) {
        //2D m=s.size(), n=t.size() dp[i][j] -> dp[m][m]?
        int m = s.size();
        int n = t.size();
        vector<vector<int>> dp(m+1, vector<int>(n+1, 0));
        vector<int> dp_1D(n+1, 0);
        dp_1D[0] = 1;
        
        for(int i = 0;i<=m; i++)
            dp[i][0] = 1;
        
        for(int j = 1;j<=n;j++)
            for(int i = 1;i<=m;i++)
            {
                //s[i-1] == t[j-1]
                //用 s = "aa",t = "a" 驗證:
/*
dp[1][1]: s="a" 湊 "a"
  沒挑第 1 個 a → dp[0][1] = 0
  挑了第 1 個 a → dp[0][0] = 1
  = 1

dp[2][1]: s="aa" 湊 "a"
  沒挑第 2 個 a → dp[1][1] = 1   (就是「用第 1 個 a」那種)
  挑了第 2 個 a → dp[1][0] = 1   (前面什麼都不用挑)
  = 2 ✓
*/
#if 1
                if(s[i-1] == t[j-1])
                {
                    dp[i][j] = (dp[i-1][j-1] + dp[i-1][j]);
                }
                else
                {
                    dp[i][j] = (dp[i-1][j]);
                }
            }
#else
            //進階(壓成 1D): 只看 ↖(dp[i-1][j-1])和 ↑(dp[i-1][j]),都是上一列的舊值 → 跟 0/1 背包一樣,j 由右往左掃。     
#endif
        return dp[m][n];
    }
};
