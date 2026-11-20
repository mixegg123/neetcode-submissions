class Solution {
public:
    bool isMatch(string s, string p) {
        int m = s.size();
        int n = p.size();
        vector<vector<bool>> dp(m+1, vector<bool>(n+1, false));
        dp[0][0] = true;
//dp[0][j]:p[j-1]=='*' 且 dp[0][j-2]
//so i shall start from zero... tough question
        for(int i = 0;i<=m;i++)
        {
            for(int j = 1;j<=n;j++)
            {
                if(p[j-1] == '*')
                {
                    //all not take from p
                    dp[i][j] = dp[i][j-2];
                    if(i>0 && (s[i-1] == p[j-2] || p[j-2] == '.'))
                    {
                        //not take s last word
                        dp[i][j] = dp[i][j] || (dp[i-1][j]);
                    }
                }
                else if (i>0 && (s[i-1] == p[j-1] || p[j-1] == '.'))
                    dp[i][j] = dp[i-1][j-1];
            }
        }
        return dp[m][n];
    }
};
