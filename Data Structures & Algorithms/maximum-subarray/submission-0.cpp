class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        //dp[i] = max(nums[i-1], dp[i-1] + nums[i-1])
        int n = nums.size();
        vector<long> dp(n+1, INT_MIN);
        int best = INT_MIN;

        for(int i = 1; i<=n; i++)
        {
            dp[i] = max((long)nums[i-1], dp[i-1]+nums[i-1]);
            best = max((long)best, dp[i]);
        }

        return best;
    }
};
