class Solution {
public:
    vector<int> countBits(int n) {
        //vector<int> res;
        vector<int> dp(n+1, 0);
        int i = 1, offset = 1;
        //count from zero to n, and in each count, produce the number of 1's in number
        //res.push_back(0);
        //while(i <= n)
        for(int i = 1;i<=n;i++)
        {
            //dp...
            //dp[1] = 1, dp[2] = 1 + dp[0], dp[3] = 1+dp[1]
            //dp[4] = 1 + dp[0]
            //if(i == (offset*2))
            //    offset = i;
            //dp[i] = 1 + dp[i-offset];
            dp[i] = dp[i>>1] + (i&1);
            //printf("dp[%d] = %d, i>>1:%d: i&1%d\n", i, dp[i], i>>1);
            //res.push_back(dp[i]);
        }
        return dp;//res;
    }
};
