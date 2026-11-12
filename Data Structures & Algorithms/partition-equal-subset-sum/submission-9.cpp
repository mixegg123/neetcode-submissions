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
            vector<bool> tmp = dp;
            for(int i = 0;i<=sum;i++)
            {
                if(i>=num)
                //left one keep stale
                    tmp[i] = tmp[i] || dp[i-num];
            }
            dp = tmp;
        }
        return dp[sum];
    }
};
