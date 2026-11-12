class Solution {
public:
    bool canPartition(vector<int>& nums) {
        //1d dp
        int sum = 0;
        for(auto num : nums)
            sum += num;

        if(sum%2)
            return false;
        sum = sum/2;

        vector<bool> dp(sum+1);
        dp[0] = true;
    
        //can we achieve the target and only take once
        for(int num : nums)
        {
            for(int i = sum;i>0;i--)
            {
                if(i>=num)
                    dp[i] = dp[i] || dp[i-num];
            }
        }
        return dp[sum];
    }
};
