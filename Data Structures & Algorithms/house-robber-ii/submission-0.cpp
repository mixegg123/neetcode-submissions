class Solution {
public:
    int rob(vector<int>& nums) {
        //dp[0]->dp[0] or dp[n-1]
        //dp[n-1] ->dp[n-1] or dp[0]
        int n = nums.size();
        if(n==1) return nums[0];
        int ans = 0;
        vector<int> dp(n, 0);
        //cosnider idx 0, and remove idx n-1, max in dp1[n-1]
        //dp[3] = max(dp(2), dp[1] + nums[2])
        for(int i=1;i<n;i++)
        {
            if(i>=2)
                dp[i] = max(dp[i-1], dp[i-2] +nums[i-1]);
            else
                dp[i] = max(dp[i-1], nums[i-1]);
        }
        ans = max(ans, dp[n-1]);
        //conside idx n-1, and remove idx 0, max in dp2[n-1]
        for(int i =1;i<n;i++)
        {
            if(i>=2)
                dp[i] = max(dp[i-1], dp[i-2] +nums[i]);
            else
                dp[i] = max(dp[i-1], nums[i]);
        }
        ans = max(ans, dp[n-1]);
        return ans;
    }
};
