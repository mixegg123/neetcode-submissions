class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int sum = 0;
        for(const int num : nums)
            sum += num;
        if(sum %2) return false;
        
        sum = sum/2;
        vector<bool> dp(sum+1, 0);
        dp[0] = 1;

        for(const int num : nums)
        {
            for(int j = sum; j>=num;j--)
            {
                dp[j] = dp[j] || dp[j-num];

            }
            if(dp[sum])
                break;
        }
        return dp[sum];
    }
};
