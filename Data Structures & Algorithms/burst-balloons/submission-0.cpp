class Solution {
public:
    int maxCoins(vector<int>& nums) {
        //push fron and back w/ 1
        nums.push_back(1);
        nums.insert(nums.begin(), 1);
        int n = nums.size();
        vector<vector<int>> dp(n, vector<int>(n, 0));

        //兩顆才能夾一顆
        for(int len = 2;len<n; len++)
        {
            for(int i = 0; i+len<n;i++)
            {
                int j = i + len;
                //i+1 ~k~ j-1
                for(int k = i+1; k<=j-1;k++)
                {
                    dp[i][j] = max(dp[i][j], dp[i][k] + 
                        nums[i] * nums[k] * nums[j] + dp[k][j]);
                }
            }
        }
        return dp[0][n-1];
    }
};
