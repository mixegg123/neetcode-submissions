class Solution {
public:
    int minDistance(string word1, string word2) {
        //2D DP! DP[i][j] while word1[0..i] to match word[0..j], minimus way to fulfill
        int m = word1.size();
        int n = word2.size();

        vector<vector<int>> dp(m+1, vector<int>(n+1, 0));
        //init
        for(int i = 0; i<=m; i++)
        {
            dp[i][0] = i;
        }
        for(int j = 0; j<=n;j++)
        {
            dp[0][j] = j;
        }

        for(int i=1;i<=m;i++)
        {
            for(int j = 1;j<=n;j++)
            {
                printf("word1[%d]:%c, word2[%d]:%c, dp[%d][%d]:%d\n",
                i-1, word1[i-1], j-1, word2[j-1], i-1, j-1, dp[i-1][j-1], dp[i-1][j-1]);
                if(word1[i-1] == word2[j-1])
                {
                    dp[i][j] = dp[i-1][j-1];
                } else
                {
                    dp[i][j] = 1 + min({
                        dp[i-1][j-1], //replace
                        dp[i-1][j], //delete
                        dp[i][j-1]} //insert
                    );
                }
                //printf("dp[%d][%d]: %d\n", i, j, dp[i][j]);
            }
        }
/*
word1="monkeys"
word2="money"
*/
        return dp[m][n];
    }
};
