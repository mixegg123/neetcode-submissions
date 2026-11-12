class Solution {
public:
    int minDistance(string word1, string word2) {
        int m = word1.size();
        int n = word2.size();
        //Declare
        vector<vector<int>> dp(m+1, vector<int>(n+1, 0));

        //Base condition
        //dp[i][0] or dp[0][j]
        for(int i = 0;i<=m;i++)
            dp[i][0] = i; //delete all i to empty
        for(int j = 0;j<=n;j++)
            dp[0][j] = j; // add j to match words
/*
Characters Match (word1[i - 1] == word2[j - 1])

No edit is needed for this character—simply inherit the diagonal subproblem:dp[i][j] = dp[i - 1][j - 1]

Characters Differ (word1[i - 1] != word2[j - 1])

Add 1 operation to the minimum of the three neighbor transitions:

Substitution (dp[i - 1][j - 1]): Replace word1[i - 1] with word2[j - 1].

Deletion (dp[i - 1][j]): Delete word1[i - 1], leaving word1[0...i-2] to match word2[0...j-1].

Insertion (dp[i][j - 1]): Insert word2[j - 1] at the end of word1[0...i-1], leaving word1[0...i-1] to match word2[0...j-2].
*/
        //State transition
        for(int i = 1;i<=m;i++)
        {
            for(int j = 1;j<=n;j++)
            {
                if(word1[i-1] == word2[j-1])
                {
                    dp[i][j] = dp[i-1][j-1];
                } else
                {
                    //1. replace
                    //2. insert
                    //3. delete
                    dp[i][j] = 1 + min({dp[i-1][j-1], 
                    dp[i-1][j], dp[i][j-1]});
                }
            }
        }
        //Answer
        return dp[m][n];
    }
};
