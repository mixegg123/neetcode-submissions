class Solution {
public:
    int numDecodings(string s) {
        //跑一次 "226"
        //dp[i] = dp[i-1] + dp[i-2]
        //1. 2,2 ; 22 -> 2
        //2. 2, 2, 6; 22, 6; dp[1] =1 -> so 2, 26 is vald
        /* 1D DP */
        int n = s.size();
        vector<int> dp(n+1, 0);
        dp[0] = 1;
        if(s[0] == '0')
            return 0;
        else
            dp[1] = 1;

        for(int i = 2;i<=n;i++)
        {
            if(s[i-1] != '0')
                dp[i] = dp[i] + dp[i-1];
            
            int val = (s[i-2] - '0')*10 + (s[i-1] - '0');
            if(10<=val && val<27)
                dp[i] = dp[i] + dp[i-2];
        }
        return dp[n];
    }
};
