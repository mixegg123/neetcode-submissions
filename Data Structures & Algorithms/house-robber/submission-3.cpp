class Solution {
public:
    int rob(vector<int>& nums) {
        //take or skip
#if 1//1D DP
        //dp[i] = max(dp[i], dp[i-2]);
        int n = nums.size();
        vector<int> dp(n+1, 0);
        dp[1] = nums[0];
        for(int i = 1;i<=n;i++)
        {
            if(i>=2)
                dp[i] = max(dp[i-1], dp[i-2] + nums[i-1]);
            else
                dp[i] = max(dp[i-1], nums[i-1]);
        }
        return dp[n];
#else
        int take = 0 , skip = 0;

        for(int num : nums)
        {
            int old_take = take;
            int old_skip = skip;

            take = old_skip+num;
            skip = max(old_skip, old_take);
        }
        return max(take, skip);
#endif
    }
};
