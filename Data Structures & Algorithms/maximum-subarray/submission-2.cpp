class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        //dp[i] = max(nums[i-1], dp[i-1] + nums[i-1])
        int n = nums.size();
        vector<int> dp(nums);
        int best = dp[0];

        for(int i = 1; i<n; i++)
        {
            dp[i] = max(nums[i], dp[i-1]+nums[i]);
            best = max(best, dp[i]);
        }

        return best;
    }
};
