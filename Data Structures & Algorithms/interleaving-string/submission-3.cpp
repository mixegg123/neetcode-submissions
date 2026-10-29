class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        int m = s1.size();
        int n = s2.size();

        if(n+m != s3.size())
            return false;

        //定義: dp[i][j] = s1 的前 i 個和 s2 的前 j 個,能不能交錯組成 s3 的前 i+j 個。
        vector<vector<bool>> dp(m+1, vector<bool>(n+1, false));
        //dp[i..][j..] -> i+j = k?
        dp[0][0] = true;
        //比第一個字
        for(int i = 0; i<=m;i++)
        {
            for(int j = 0;j<=n;j++)
            {
                if(i == 0 && j == 0)
                    continue;
                //s1[i-1] 第 i word
                //s2[j-1] 第 j word
                //s3[i+j-1] 第 i+j-1 word
                char c = s3[i+j-1];
                dp[i][j] = ((i>0) && s1[i-1] == c && dp[i-1][j]) || 
                    ((j>0) && s2[j-1] == c && dp[i][j-1]);
            }
        }
        return dp[m][n];
    }
};
