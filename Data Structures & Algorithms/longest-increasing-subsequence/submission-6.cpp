class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        //it self is 1
        vector<int> dp(n, 1);
        int max_len = 1;
        for(int i = 0;i<n;i++)
        {
            for(int j = 0;j<i;j++)
            {
                //printf("i:%d, j:%d, dp[i]:%d, dp[j]:%d\n",
                //i, j, dp[i], dp[j]);
                if(nums[i] > nums[j])
                    dp[i] = max(dp[i],  dp[j] + 1);
                max_len = max(max_len, dp[i]);
            }
        }
        return max_len;
    }
};
