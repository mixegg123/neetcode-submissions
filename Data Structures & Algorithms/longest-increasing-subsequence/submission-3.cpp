class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        //if face small (top >=), drop old (big), insert new
        //stack X
        // 2D DP
        int n = nums.size();
        int max_len = 0;
        vector<int> dp(n, 1);
        for(int i = 0;i<n;i++)
        {
            for(int j = 0;j<i;j++)
            {
                //printf("nums[%d]: %d,nums[%d]: %d\n",i,nums[i],j,nums[j]);

                if(nums[j] < nums[i])
                    dp[i] = max(dp[i], dp[j] + 1);
                //printf("dp[%d]:%d\n", i ,dp[i]);
            }
            max_len = max(max_len, dp[i]);
        }
        return max_len;
    }
};
