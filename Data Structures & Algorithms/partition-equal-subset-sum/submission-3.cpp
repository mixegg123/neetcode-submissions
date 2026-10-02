class Solution {
public:
    bool canPartition(vector<int>& nums) {
#if 1 //2d
    //(w - nums[i-1]) + nums[i-1] = w
    //dp[i][j]: i is for nums, j is for target, i代表前面n個
    int target = 0;
    for(const int num : nums)
        target += num;
    if(target %2) return false;
        
    target = target/2;    
    int n = nums.size();

    vector<vector<bool>> dp(n+1, vector<bool>(target+1, false));
    for(int i = 0; i<=n; i++)
        dp[i][0] = true;

    for(int i = 1; i <=n ; i ++)
    {
        for(int j = 0 ; j<=target ;j++)
        {
            //printf("dp[%d][%d]:%d, dp[%d][%d]:%d, nums[i-1]:%d\n", i, j, (bool)dp[i][j],
            //i-1, j, (bool)dp[i-1][j], (bool)nums[i-1]);
            dp[i][j] = dp[i-1][j];//not take
            if(j >= nums[i-1])
                dp[i][j] = dp[i][j] || dp[i-1][j-nums[i-1]];
        }
    }

    return dp[n][target];

#else

#if 0// right to left
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
#else //left to right w/ temp dp
            int sum = 0;
        for(const int num : nums)
            sum += num;
        if(sum %2) return false;
        
        sum = sum/2;
        vector<bool> dp(sum+1, 0);
        //dp[target] false/true: can fulfill or not
        dp[0] = true;

        for(const int num : nums)
        {
            vector<bool> tmp = dp;
            for(int i = 0; i<=sum; i++)
            {
                if(i>=num)
                    tmp[i] == dp[i] || dp[i-num]
            }
            dp = tmp;
        }
        return dp[sum];
#endif
#endif
    }
};
